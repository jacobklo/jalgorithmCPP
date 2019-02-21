//
// Created by Jacob Lo on Feb 20, 2019
//

// https://www.geeksforgeeks.org/bridge-design-pattern/

#pragma once

#include <iostream>

using namespace std;

namespace Bridge {
    // Implementor for bridge pattern
    struct Workshop {
        virtual void work() = 0;
    };

// Concrete implementation 1 for bridge pattern
    struct Produce : public Workshop {
        void work() { cout << "Produced "; }
    };

// Concrete implementation 2 for bridge pattern
    struct Assemble : public Workshop {
        void work() { cout << "Assembled " << endl; }
    };


// abstraction in bridge pattern
    struct Vehicle {
        Vehicle(Workshop *w1, Workshop *w2) : workshop1(w1), workshop2(w2) {}

        virtual void make() = 0;

        Workshop *workshop1;
        Workshop *workshop2;
    };

// Refine abstraction 1 in bridge pattern
    struct Car : public Vehicle {
        Car(Workshop *w1, Workshop *w2) : Vehicle(w1, w2) {}

        void make() {
            cout << "Car ";
            workshop1->work();
            workshop2->work();
        }
    };

// Refine abstraction 2 in bridge pattern
    struct Bus : public Vehicle {
        Bus(Workshop *w1, Workshop *w2) : Vehicle(w1, w2) {}

        void make() {
            cout << "Bus ";
            workshop1->work();
            workshop2->work();
        }
    };

    void test() {
        Car c ( new Produce(), new Assemble() );
        c.make();
        Bus b ( new Produce(), new Assemble() );
        b.make();
    }
}