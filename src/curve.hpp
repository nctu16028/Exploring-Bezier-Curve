#pragma once
#include <vector>
#include "point.hpp"

class Curve
{
public:
    Curve();
    void printCurvePoints(int num); // for debugging

private:
    Point deCasteljau(double t, int cnt_start, int degree);
    std::vector<Point> control;  // contain n+1 points, where n is the degree
};

