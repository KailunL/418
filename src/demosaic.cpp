#include "demosaic.h"

void demosaic(
        const std::vector<unsigned char> & bayer,
        const int & width,
        const int & height,
        std::vector<unsigned char> & rgb) {
    rgb.resize(width * height * 3);
    ////////////////////////////////////////////////////////////////////////////
    // Add your code here
    ////////////////////////////////////////////////////////////////////////////
    int color1 = 0;
    int color2 = 0;

    int org_channel = 0;
    int up = 1;
    int left = 1;
    for (int i = 0; i < height; i++) {
        int left = 1;
        for (int j = 0; j < width; j++) {
            color1 = width * i + j;
            color2 = width * i * 3 + 3 * j;
            int directions = 8;
            int red = 0;
            int blue = 0;
            int green = 0;
            int Cred = 0;
            int Cblue = 0;
            int Cgreen = 0;

            //            std::vector<int> red;
            //            std::vector<int> green;
            //            std::vector<int> blue;


            if (left == up) {//green
                org_channel = 1;
                if (i != 1) {//has top
                    Cred++;
                    red += (int) bayer[(i - 1) * width + j];
                }
                if (i != height - 1) { //has but
                    Cred++;
                    red += (int) bayer[(i + 1) * width + j];
                }
                if (j != 1) {//left
                    Cblue++;
                    blue += (int) bayer[i * width + j - 1];
                }
                if (j != width - 1) {//right
                    Cblue++;
                    blue += (int) bayer[i * width + j + 1];
                }


            } else if (left == 1 && up == 0) { //red
                org_channel = 0;
                if (i != 1) {//has top
                    Cgreen++;
                    green += (int) bayer[(i - 1) * width + j];
                    if (j != 1) {//top left
                        Cblue++;
                        blue += (int) bayer[(i - 1) * width + j - 1];
                    }
                    if (j != width - 1) {//top right
                        Cblue++;
                        blue += (int) bayer[(i - 1) * width + j + 1];
                    }

                }
                if (i != height - 1) { //has but
                    Cgreen++;
                    green += (int) bayer[(i + 1) * width + j];
                    if (j != 1) {//but left
                        Cblue++;
                        blue += (int) bayer[(i + 1) * width + j - 1];
                    }
                    if (j != width - 1) {//but right
                        Cblue++;
                        blue += (int) bayer[(i + 1) * width + j + 1];
                    }
                }
                if (j != 1) {//left
                    Cgreen++;
                    green += (int) bayer[i * width + j - 1];
                }
                if (j != width - 1) {//right
                    Cgreen++;
                    green += (int) bayer[i * width + j + 1];
                }


            } else { //blue
                org_channel = 2;
                if (i != 1) {//has top
                    Cgreen++;
                    green += (int) bayer[(i - 1) * width + j];
                    if (j != 1) {//top left
                        Cred++;
                        red += (int) bayer[(i - 1) * width + j - 1];
                    }
                    if (j != width - 1) {//top right
                        Cred++;
                        red += (int) bayer[(i - 1) * width + j + 1];
                    }

                }
                if (i != height - 1) { //has but
                    Cgreen++;
                    green += (int) bayer[(i + 1) * width + j];
                    if (j != 1) {//but left
                        Cred++;
                        red += (int) bayer[(i + 1) * width + j - 1];
                    }
                    if (j != width - 1) {//but right
                        Cred++;
                        red += (int) bayer[(i + 1) * width + j + 1];
                    }
                }
                if (j != 1) {//left
                    Cgreen++;
                    green += (int) bayer[i * width + j - 1];
                }
                if (j != width - 1) {//right
                    Cgreen++;
                    green += (int) bayer[i * width + j + 1];
                }
            }


            if (Cred != 0)
                red = red / Cred;
            if (Cgreen != 0)
                green = green / Cgreen;
            if (Cblue != 0)
                blue = blue / Cblue;
            //reflected[color2+channel] = input[color2+channel];

            if (org_channel == 0) {
                rgb [color2] = bayer[color1];
                rgb [color2+1] = green;
                rgb [color2+2] = blue;
            }//red

            else if (org_channel == 1) {
                rgb [color2] = red;
                rgb [color2+1] = bayer[color1];
                rgb [color2+2] = blue;
            }//green
            else {
                rgb [color2] = red;
                rgb [color2+1] = green;
                rgb [color2+2] = bayer[color1];
            }//blue
            //reflected[color2+channel] = input[color2+channel];
            if (left == 0)
                left++;
            else
                left--;

        }

        if (up == 0)
            up++;
        else
            up--;


    }




}
