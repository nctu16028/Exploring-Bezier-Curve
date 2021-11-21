#include "curve.hpp"
#include <iostream>

Curve::Curve()
{
    int n;
    std::cin >> n;
    for(int i=0; i<=n; i++)
    {
        Point cnt;
        std::cin >> cnt.px >> cnt.py;
        control.push_back(cnt);
    }

}

void Curve::printCurvePoints(int num)
{
    double interval = 1.0 / (double)num;
    for(int i=0; i<=num; i++)
    {
        double t = 0.0 + interval*i;
        Point p = Curve::deCasteljau(t, 0, (int)control.size()-1);
        std::cout << p.px << "\t" << p.py << std::endl;
    }
}

Point Curve::deCasteljau(double t, int cnt_start, int degree)
{
    // Termination condition
    if(degree == 0)
        return control[cnt_start];

    // Recursive part
    Point left_ref = Curve::deCasteljau(t, cnt_start, degree-1);
    Point right_ref = Curve::deCasteljau(t, cnt_start+1, degree-1);
    Point ans;
    ans.px = (1-t) * left_ref.px + t * right_ref.px;
    ans.py = (1-t) * left_ref.py + t * right_ref.py;
    return ans;
}

