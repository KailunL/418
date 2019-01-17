#include "over.h"

void over(
        const std::vector<unsigned char> & A,
        const std::vector<unsigned char> & B,
        const int & width,
        const int & height,
        std::vector<unsigned char> & C) {
    C.resize(A.size());
    ////////////////////////////////////////////////////////////////////////////
    // Add your code here
    ////////////////////////////////////////////////////////////////////////////
    int color1 = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            color1 = i * width * 4 + j * 4;
            double alpha_A = (double) A[color1 + 3]/255;
            double alpha_b = (double) B[color1 + 3]/255;
            for (int channel = 0; channel < 3; channel++) {
                C[color1 + channel] = (unsigned char)(alpha_A * (double) A[color1 + channel] + (1 - alpha_A) *alpha_b *(double) B[color1 + channel]);
                //reflected[color2+channel] = input[color2+channel];
            }
            C[color1 + 3]= (unsigned char)(alpha_A + alpha_b*(1-alpha_A))*255;

        }
    }





}
