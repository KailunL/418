#include "hsv_to_rgb.h"
#include <cmath>
#include <math.h>
void hsv_to_rgb(
        const double h,
        const double s,
        const double v,
        double & r,
        double & g,
        double & b) {
    ////////////////////////////////////////////////////////////////////////////
    // Replace with your code here:
    r = 0;
    g = 0;
    b = 0;

//    if (s == 0)
//        return;
    double max = v;
    double min = v - s*v;
    
    double C = v*s;
    double H_ = h / 60;

    double X = C * (1 - std::abs(fmod(H_, 2) - 1));

    double m = v - C;

    double R1 = 0;
    double G1 = 0;
    double B1 = 0;
        if (H_ >= 0 && H_ <= 1) {
            R1 = C;
            G1 = X;
            B1 = 0;
        } else if (H_ > 1 && H_ <= 2) {
            R1 = X;
            G1 = C;
            B1 = 0;
        } else if (H_ > 2 && H_ <= 3) {
            R1 = 0;
            G1 = C;
            B1 = X;
        } else if (H_ > 3 && H_ <= 4) {
            R1 = 0;
            G1 = X;
            B1 = C;
        } else if (H_ > 4 && H_ <= 5) {
            R1 = X;
            G1 = 0;
            B1 = C;
        } else if (H_ > 5 && H_ <= 6) {
            R1 = C;
            G1 = 0;
            B1 = X;
        }

    r = R1 + m;
    g = G1 + m;
    b = B1 + m;



    ////////////////////////////////////////////////////////////////////////////
}
