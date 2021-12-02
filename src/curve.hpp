#pragma once
#include <vector>
#include "point.hpp"

class Curve
{
public:
    Curve(int deg);
    void setControlPoints(int i, double x, double y);
    Point getCurvePoint(double time);

private:
    Point deCasteljau(double t, int cnt_start, int degree);
    int degree;
    std::vector<Point> control;  // contain n+1 points, where n is the degree
};

