 // Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Image.h"
#include "processing.h"
#include <fstream>
#include <string>
#include <cassert>
#include <cstdlib>
#include <iostream>

int main (int argc, char * argv[]) {
    if (argc < 4 || argc > 5) {
        std::cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
        << "WIDTH and HEIGHT must be less than or equal to original" << std::endl;
        return 1;
    }
    
    std::string input_file = argv[1], output_file = argv[2];
    std::ifstream ins(input_file);
    std:: ofstream outs(output_file);
    if (!ins.is_open() || !outs.is_open()) {
        std::cout << "Error opening file: "
        << input_file << std::endl;
        return 1;
    }
    
    int width = atoi(argv[3]), height;
    Image *img = new Image;
    Image_init(img, ins);
    if (argc == 5) {
        height = atoi(argv[4]);
    }
    else {
        height = Image_height(img);
    }
    
    if (width <= 0 || width > Image_width(img)
        ||height <= 0 || height > Image_height(img)) {
        std::cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
        << "WIDTH and HEIGHT must be less than or equal to original" << std::endl;
        return 1;
    }
    
    
    seam_carve(img, width, height);
    Image_print(img, outs);
    ins.close();
    outs.close();
    delete img;
    return 0;
}
