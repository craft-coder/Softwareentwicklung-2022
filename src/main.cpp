#include <fstream>

int main() {

    // Image
    const int imageWidth = 3;
    const int imageHeigth = 2;

    // Open our file

    std::ofstream filestream;
    filestream.open("example.ppm");

    filestream << "P3\n" << imageWidth << ' ' << imageHeigth << "\n255\n";

    for (int y = imageHeigth - 1; y >= 0; y--) {
        for (int x = 0; x < imageWidth; x++) {

            // Write [0,255] value of each color component
            auto red = 255;
            auto green = 0;
            auto blue = 0;

           filestream << red << ' ' << green << ' ' << blue << '\n';
        }
    }

    filestream.close();

    return 0;
}
