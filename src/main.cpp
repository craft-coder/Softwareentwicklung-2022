#include <fstream>

int main() {

    auto width = 30;
    auto height = 20;

    std::ofstream filestream;
    filestream.open("exampleImage.ppm");

    filestream << "P3\n";
    filestream << width << " " << height << "\n";
    filestream << 255 << "\n";

    for (auto y = 0; y < height; y++) {
        for (auto x = 0; x < width; x++) {
            auto red = 255;
            auto green = 255;
            auto blue = 255;

            filestream << red << " " << green << " " << blue << "\n";
        }
    }

    filestream.close();

    return 0;
}
