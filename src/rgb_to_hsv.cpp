#include "rgb_to_hsv.h"

void rgb_to_hsv(
        const double r,
        const double g,
        const double b,
        double & h,
        double & s,
        double & v) {
    ////////////////////////////////////////////////////////////////////////////
    // Replace with your code here:
    h = 0;
    s = 0;
    v = 0;
    double max = r;
    double min = r;

    if (max < g)
        max = g;
    if (max < b)
        max = b;

    if (min > g)
        min = g;
    if (min > b)
        min = b;

    if (max == min)
        h = 0;
    else if (max == r)
        h = ((g - b) / (max - min)) * 60;
    else if (max == g)
        h = (2 + (b - r) / (max - min)) * 60;
    else if (max == b)
        h = (4 + (r - g) / (max - min)) * 60;
    if (h < 0)
        h = h+ 360;


    v = max;

    if (max == 0)
        s = 0;
    else
        s=(max - min) / max;


    ////////////////////////////////////////////////////////////////////////////
}
