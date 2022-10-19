#include "cycloid.h"
#include <cmath>
#include <iostream>

using namespace std;

double f(double r) {
    return (r * r * M_PI);
}

double simpson_integral(double a, double b, int n);

double count_integral(double a, double b, int n);

namespace CycloidSpace {

    Cycloid::Cycloid(double R, double T) {
        r = R;
        t = T;
        check();
    }

    void Cycloid::check() const {
        if (r <= 0) {
            throw std::logic_error("raduis can't be zero or lower");
        }
        if (t <= 0) {
            throw std::logic_error("angle can't be zero or lower");
        }
    }

    Point Cycloid::point() const {
        double x = (double) r * t - r * sin(t);
        double y = (double) r - r * cos(t);
        Point point;
        point.x = x;
        point.y = y;
        return point;
    }

    double Cycloid::cartesian_coordinates() const {
        Point point = Cycloid::point();
        double y = point.y;
        return r * acos((r - y) / r) - sqrt(2 * r * y - y * y);
    }

    double Cycloid::radius_of_curvature() const {
        return 4 * r * sin(t / 2);
    }

    double Cycloid::length() const {
        return 8 * r;
    }

    double Cycloid::square() const {
        return 3 * M_PI * r * r;
    }

    double Cycloid::square_from_rotation() const {
        double length = 2 * M_PI * r;
        return (length / 2) * (length / 2) * M_PI;
    }

    double Cycloid::volume_from_rotation() const {
        return count_integral(0, 2 * r, 8000);
    }

    double Cycloid::simpson_volume_from_rotation() const {
        return simpson_integral(0, 2 * r, 7000);
    }

    void Cycloid::change_coordinates(double a, double b) {
        r = a;
        t = b;
    }
}

double count_integral(double a, double b, int n) {
    double s = (f(a) + f(b)) / 2;
    double h = (b - a) / n;
    for (int i = 1; i < n; i++) {
        s = s + f(a + i * h);
    }
    return h * s;
}

double simpson_integral(double a, double b, int n) {
    float h = (b - a) / n;
    float x[n + 1], fx[n + 1];
    for (int i = 0; i <= n; i++) {
        x[i] = a + i * h;
        fx[i] = f(x[i]);
    }
    float res = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || i == n) {
            res += fx[i];
        } else if (i % 2 != 0) {
            res += 4 * fx[i];
        } else {
            res += 2 * fx[i];
        }
    }
    res = res * (h / 3);
    return res;
}

