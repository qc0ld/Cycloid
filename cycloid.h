#ifndef CYCLOID_H
#define CYCLOID_H

#include <cmath>

typedef struct Point Point;
struct Point {
    double x;
    double y;
};

namespace CycloidSpace {
    class Cycloid {
    private:
        double r;
        double t;
    public:

        Cycloid(double R, double T);

        void check() const;

        Point point() const;

        double cartesian_coordinates() const;

        double radius_of_curvature() const;

        double length() const;

        double square() const;

        double square_from_rotation() const;

        double volume_from_rotation() const;

        double simpson_volume_from_rotation() const;

        void change_coordinates(double a, double b);
    };
}
#endif //CYCLOID_H
