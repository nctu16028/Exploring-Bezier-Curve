#pragma once

class Point
{
public:
    double   X() const;     // x getter
    double & X();           // x setter
    double   Y() const;     // y getter
    double & Y();           // y setter
    Point operator+(Point const &other);    // Point addition
    Point operator*(double c);              // Scaler multiplication

private:
    double coord[2];
};

