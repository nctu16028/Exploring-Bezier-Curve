#!/usr/bin/env python3

import sys
import _curve
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

if __name__ == '__main__':
    if len(sys.argv) < 2:
        raise Exception("Please specify the input data file")

    cnt_xs = list()
    cnt_ys = list()
    filepath = "./testcase/" + sys.argv[1]
    with open(filepath, 'r') as f:
        n = int(f.readline().strip())
        bezier = _curve.Curve(n)
        for i in range(n+1):
            line = f.readline().strip().split()
            x = int(line[0])
            y = int(line[1])
            cnt_xs.append(x)
            cnt_ys.append(y)
            bezier.setControlPoints(i, x, y)

    # Plot animation
    fig, ax = plt.subplots()
    fig.set_tight_layout(True)

    # Query the figure's on-screen size and DPI. Note that when saving the figure to
    # a file, we need to provide a DPI for that separately.
    print('fig size: {0} DPI, size in inches {1}'.format(
        fig.get_dpi(), fig.get_size_inches()))

    # Plot a scatter that persists (isn't redrawn)
    ax.scatter(cnt_xs, cnt_ys)

    # Initialize the curve and the auxiliary lines
    line_set = list()
    for i in range(n):
        line_plotted, = ax.plot([], [], 'b-', linewidth=1)
        line_set.append(line_plotted)

    curve_xs = list()
    curve_ys = list()
    num_point = 100
    interval = 1.0 / num_point
    curve_plotted, = ax.plot(curve_xs, curve_ys, 'r-', linewidth=3)

    def update(frame):
        if frame == -1:     # clear screen
            curve_xs.clear()
            curve_ys.clear()
            return
        t = 0.0 + interval * frame

        for i in range(n):
            sp = _curve.Point(cnt_xs[i], cnt_ys[i])
            ep = _curve.Point(cnt_xs[i+1], cnt_ys[i+1])
            ip = _curve.innerPoint(sp, ep, t)
            lineX = [sp.X, ip.X]
            lineY = [sp.Y, ip.Y]
            line_set[i].set_data((lineX, lineY))

        point = bezier.getCurvePoint(t)
        curve_xs.append(point.X)
        curve_ys.append(point.Y)
        curve_plotted.set_data((curve_xs, curve_ys))

    anim = FuncAnimation(fig, update, frames=np.arange(-1, num_point+1), interval=1)
    plt.show()

