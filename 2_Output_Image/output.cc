#include "C:\bellows\Ray_Tracing\veclib\color.h"
#include "C:\bellows\Ray_Tracing\veclib\vec3.h"

#include <iostream>
#include <fstream>

int main() {

    // Image

    int image_width = 256;
    int image_height = 256;

    // Render

    std::ofstream out_file("image.ppm");

    //out_file << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    out_file << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), 0);
            write_color(out_file, pixel_color);
        }
    }

    std::clog << "\rDone.                 \n";
}