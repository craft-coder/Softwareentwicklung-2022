#include "Ray.h"
#include "Vec3.h"
#include <fstream>

using namespace raytracer;

Color background(const Ray& ray) {
    auto startColor = Color(0.5, 0.7, 1.0);
    auto endColor = Color(1.0, 1.0, 1.0);

    auto yComponent = ray.getDirection().getY();
    auto t = 0.5 * (yComponent + 1.0);
    return (1.0 - t) * startColor + t * endColor;
}

void writeColor(std::ofstream& filestream, const Color& color) {
    auto red = static_cast<int>(255.999 * color.getX());
    auto green = static_cast<int>(255.999 * color.getY());
    auto blue = static_cast<int>(255.999 * color.getZ());

    filestream << red << " " << green << " " << blue << "\n";
}

int main() {

    std::ofstream filestream;
    filestream.open("exampleImage.ppm");

    // Image settings
    auto width = 400;
    auto height = 300;
    auto aspectRatio = static_cast<double>(width) / height;

    // Camera settings
    auto viewportHeight = 2.0;
    auto viewportWidth = aspectRatio * viewportHeight;
    auto focalLength = 1.0;

    auto origin = Point3(0.0, 0.0, 0.0);
    auto horizontal = Vec3(viewportWidth, 0.0, 0.0);
    auto vertical = Vec3(0.0, viewportHeight, 0.0);
    auto lowerLeftCorner = origin - Vec3(0.0, 0.0, focalLength) - horizontal / 2.0 - vertical / 2.0;

    filestream << "P3\n";
    filestream << width << " " << height << "\n";
    filestream << 255 << "\n";

    for (auto y = 0; y < height; y++) {
        for (auto x = 0; x < width; x++) {
            auto u = static_cast<double>(x) / (width - 1);
            auto v = static_cast<double>(y) / (height - 1);

            auto direction = lowerLeftCorner + u * horizontal + v * vertical - origin;
            direction.normalize();

            auto ray = Ray(origin, direction);
            auto color = background(ray);
            writeColor(filestream, color);
        }
    }

    filestream.close();

    return 0;
}
