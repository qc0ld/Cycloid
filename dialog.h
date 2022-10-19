#ifndef DIALOG_H
#define DIALOG_H

#include "cycloid.h"

using namespace CycloidSpace;
namespace Dialog {
    void point(Cycloid &cycloid);

    void cartesian_coordinates(Cycloid &cycloid);

    void radius_of_curvature(Cycloid &cycloid);

    void length(Cycloid &cycloid);

    void square(Cycloid &cycloid);

    void square_from_rotation(Cycloid &cycloid);

    void volume_from_rotation(Cycloid &cycloid);

    void change_coordinates(Cycloid &cycloid);
}

#endif //DIALOG_H
