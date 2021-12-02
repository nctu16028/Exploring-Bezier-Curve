#include "curve.hpp"
#include <pybind11/pybind11.h>

PYBIND11_MODULE(_curve, m)
{
    pybind11::class_<Curve>(m, "Curve")
        .def(pybind11::init<int>())
        .def("setControlPoints", &Curve::setControlPoints)
        .def("printCurvePoints", &Curve::printCurvePoints);
}

