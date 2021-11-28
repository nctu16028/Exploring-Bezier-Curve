#include "point.hpp"

// x getter
double Point::X() const
{
    return coord[0];
}

// x setter
double & Point::X()
{
    return coord[0];
}

// y getter
double Point::Y() const
{
    return coord[1];
}

// y setter
double & Point::Y()
{
    return coord[1];
}

// Point addition
Point Point::operator+(Point const &other)
{
    Point ans;
    ans.X() = coord[0] + other.X();
    ans.Y() = coord[1] + other.Y();
    return ans;
}

// Scaler multiplication
Point Point::operator*(double c)
{
    Point ans;
    ans.X() = coord[0] * c;
    ans.Y() = coord[1] * c;
    return ans;
}

