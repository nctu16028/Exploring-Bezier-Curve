#include "curve.hpp"
#include <iostream>

Curve::Curve(int deg)
{
    degree = deg;
    control.resize(deg+1);
}

void Curve::setControlPoints(int i, double x, double y)
{
    // Exception handling
    try
    {
        if(i < 0 || i > degree)
            throw "Invalid control point";
    }
    catch(char *excp)
    {
        std::cout << excp << std::endl;
    }

    control[i].X() = x;
    control[i].Y() = y;
}

void Curve::printCurvePoints(int num)
{
    double interval = 1.0 / (double)num;
    for(int i=0; i<=num; i++)
    {
        double t = 0.0 + interval*i;
        Point p = Curve::deCasteljau(t, 0, (int)control.size()-1);
        std::cout << p.X() << "\t" << p.Y() << std::endl;
    }
}

Point Curve::deCasteljau(double t, int cnt_start, int degree)
{
    // Exception handling
    try
    {
        if(t > 1.0 || t < 0.0)
            throw "Invalid curve point";
        if(degree < 0 || degree >= (int)control.size())
            throw "Invalid degree";
        if(cnt_start < 0 || cnt_start >= (int)control.size())
            throw "Invalid control points";
    }
    catch(char *excp)
    {
        std::cout << excp << std::endl;
    }

    // Termination condition
    if(degree == 0)
        return control[cnt_start];

    // Recursive part
    Point left_ref = Curve::deCasteljau(t, cnt_start, degree-1);
    Point right_ref = Curve::deCasteljau(t, cnt_start+1, degree-1);
    Point ans = left_ref * (1-t) + right_ref * t;
    return ans;
}

