//
// Created by Jacob Lo on Feb 19, 2019
//

#pragma once
#include <iostream>

using namespace std;

namespace Builder {
    class Car {
        Car(string c, string e) : color(c), engine(e){}

    public:
        const string color, engine;

        struct CarBuilder {
            string color = "Red", engine = "Boxer";

        public:
            CarBuilder& setColor(string c) {
                this->color = c;
                return *this;
            }
            CarBuilder& setEngine(string e) {
                this->engine = e;
                return *this;
            }

            Car build() {
                return Car(color, engine);
            }
        };
    };

    ostream& operator<< ( ostream& out, const Car& c) {
        out << "This is a " << c.color << " color car with " << c.engine << " engine." << endl;
        return out;
    }

    void test() {
        Car c1 = Car::CarBuilder().setColor("Blue").setEngine("Inline").build();
        Car c2 = Car::CarBuilder().setColor("Black").setEngine("V6").build();

        Car::CarBuilder builder;
        Car c3 = builder.build();

        builder.setColor("Green");
        Car c4 = builder.build();

        builder.setEngine("V8");
        Car c5 = builder.build();

        cout << c1 << c2 << c3 << c4 << c5;
    }

}