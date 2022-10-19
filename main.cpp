#include <iostream>
#include "cycloid.h"
#include "handle.h"
#include "dialog.h"

using namespace std;
using namespace Dialog;
using namespace CycloidSpace;

void menu() {
    cout << "1. Display x and y" << endl;
    cout << "2. Display Cartesian coordinate solution for x" << endl;
    cout << "3. Display radius of corvature" << endl;
    cout << "4. Display lenght of cycloid" << endl;
    cout << "5. Display square of cycloid" << endl;
    cout << "6. Display square from rotation" << endl;
    cout << "7. Display volume from rotation" << endl;
    cout << "8. Set new coordinates" << endl;
    cout << "0. Exit" << endl;
}


int main() {
    double R = read_int("radius");
    double T = read_int("angle") * M_PI / 180;
    CycloidSpace::Cycloid cycloid(R, T);
    void (*foo[])(Cycloid &) = {nullptr, point, cartesian_coordinates, radius_of_curvature,
                                length, square, square_from_rotation, volume_from_rotation, change_coordinates};
    while (1) {
        menu();
        int number = read_menu_int(">");
        if (number == 0) {
            break;
        }
        foo[number](cycloid);
    }
    return 0;
}

