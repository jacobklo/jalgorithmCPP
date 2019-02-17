//
// Created by Jacob Lo on Feb 17, 2019
//

#pragma once

#include <string>
#include <iostream>

using namespace std;

namespace AbstractFactory {

/*
 * Customer will not know file will supported
 */
    struct FileType {
        virtual string getFileExtension() = 0;
    };

    struct DocFile : public FileType {
        string getFileExtension() { return "docx"; }
    };

    struct MP3File : public FileType {
        string getFileExtension() { return "mp3"; }
    };


/*
 * Functions is generized. so when add support for new file, customer don't need to change customer code.
 * check doSomethingWithFileThisFile()
 * This logic also hide from customer
 */
    struct FileManipulationFactory {
        virtual void doSomethingWithFileThisFile() = 0;
    };

    struct DocxFileManipulationFactory : public FileManipulationFactory {
        void doSomethingWithFileThisFile() {
            cout << " DocxFileManipulationFactory for docx" << endl;
        }
    };

    struct MP3FileManipulationFactory : public FileManipulationFactory {
        void doSomethingWithFileThisFile() {
            cout << " MP3FileManipulationFactory for mp3" << endl;
        }
    };

/*
 * simple switch cases for getting correct factories
 * input as a string, so customer dont need to know the object in advance
 * we do so to hide what file we supported correctly.
 */
    FileManipulationFactory &factory(string whatFileType) {

        if (whatFileType == "Word") {
            static DocxFileManipulationFactory dfn = DocxFileManipulationFactory();
            return dfn;
        } else if (whatFileType == "Music") {
            static MP3FileManipulationFactory mfn = MP3FileManipulationFactory();
            return mfn;
        } else {
            cout << "File Type not yet supported";
            throw 20;
        }
    }

    void AbstractFactoryMain() {
        factory("Word").doSomethingWithFileThisFile();
        factory("Music").doSomethingWithFileThisFile();
    }
}