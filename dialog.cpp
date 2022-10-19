#include "dialog.h"
#include <iostream>
#include "handle.h"


using namespace std;


namespace Dialog {
    void point(Cycloid &cycloid) {
        Point point = cycloid.point();
        cout << "x: " << point.x << endl << "y: " << point.y << endl;
    }

    void cartesian_coordinates(Cycloid &cycloid) {
        cout << "Result: " << cycloid.cartesian_coordinates() << endl;
    }

    void radius_of_curvature(Cycloid &cycloid) {
        cout << "Result: " << cycloid.radius_of_curvature() << endl;
    }

    void length(Cycloid &cycloid) {
        cout << "Result: " << cycloid.length() << endl;
    }

    void square(Cycloid &cycloid) {
        cout << "Result: " << cycloid.square() << endl;
    }

    void square_from_rotation(Cycloid &cycloid) {
        cout << "Result: " << cycloid.square_from_rotation() << endl;
    }

    void volume_from_rotation(Cycloid &cycloid) {
        cout << "Result: " << cycloid.volume_from_rotation() << endl;
    }

    void change_coordinates(Cycloid &cycloid) {
        double r = read_int("new radius");
        double t = read_int("new angle") * M_PI / 180;
        cycloid.change_coordinates(r, t);
        cout << "Coordinates were changed" << endl;
    }
}