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
    bezier.printCurvePoints(10)

