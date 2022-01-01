#include "curve.hpp"
#include <pybind11/pybind11.h>

PYBIND11_MODULE(_curve, m)
{
    pybind11::class_<Point>(m, "Point")
        .def(pybind11::init<double, double>())
        .def_property_readonly("X", pybind11::overload_cast<>(&Point::X, pybind11::const_))
        .def_property_readonly("Y", pybind11::overload_cast<>(&Point::Y, pybind11::const_));

    m.def("innerPoint", &inner);

    pybind11::class_<Curve>(m, "Curve")
        .def(pybind11::init<int>())
        .def("setControlPoints", &Curve::setControlPoints)
        .def("getCurvePoint", &Curve::getCurvePoint);
}

