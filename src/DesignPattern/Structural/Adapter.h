//
// Created by Jacob Lo on Feb 19, 2019
//

#pragma once

#include <string>
#include <iostream>

using namespace std;

namespace Adapter {
    /*
     * Interface of a music player
     */
    struct MusicPlayer {
        virtual void play(string fileType) = 0;
    };

/*
 * Interface of a video player
 */
    struct VideoPlayer {
        virtual void playSoundOnly() = 0;
    };

    struct MP4VideoPlayer : public VideoPlayer {
        void playSoundOnly() { cout << " Playing Mp4 video but sound only" << endl; }
    };

    struct WMVVideoPlayer : public VideoPlayer {
        void playSoundOnly() { cout << " Playing WMV video but sound only" << endl; }
    };


/*
 * Convert handle sound only part logic that handle a video file
 * so we can adapt this into a Music player
 */
    class VideoToMusicAdapter : public MusicPlayer {
    public:
        VideoToMusicAdapter(string fileType) : m_FileType(fileType) {
            if (fileType == "mp4") {
                m_VideoPlayer = new MP4VideoPlayer();
            } else if (fileType == "wmv") {
                m_VideoPlayer = new WMVVideoPlayer();
            }
        }

        ~VideoToMusicAdapter() { delete (m_VideoPlayer); }

        void play(string fileType) {
            m_VideoPlayer->playSoundOnly();
        }

    private:
        VideoPlayer *m_VideoPlayer = nullptr;
        string m_FileType = "";
    };


    struct CompanyAMusicPlayer : public MusicPlayer {
        void play(string fileType) {
            if (fileType == "mp3") {
                cout << " Playing mp3" << endl;
            }
                // if it is a video file
            else if (fileType == "wmv" || fileType == "mp4") {
                VideoToMusicAdapter vtma(fileType);
                vtma.play(fileType);
            }
        }
    };

    void test() {
        CompanyAMusicPlayer mp;
        mp.play("mp3");
        mp.play("mp4");
        mp.play("wmv");
    }
}