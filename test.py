#!/usr/bin/env python3

import sys
import _curve

if __name__ == '__main__':
    if len(sys.argv) < 2:
        raise Exception("Please specify the input data file")

    filepath = "./testcase/" + sys.argv[1]
    with open(filepath, 'r') as f:
        n = int(f.readline().strip())
        bezier = _curve.Curve(n)
        for i in range(n+1):
            line = f.readline().strip().split()
            x = int(line[0])
            y = int(line[1])
            bezier.setControlPoints(i, x, y)

    curve_points = []
    num_point = 10
    interval = 1.0 / num_point
    for i in range(num_point+1):
        t = 0.0 + interval * i
        point = bezier.getCurvePoint(t)
        curve_points.append((point.X, point.Y))
        #print("{}\t{}".format(point.X, point.Y))
        #print(curve_points)

