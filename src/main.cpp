#include "Hittables.h"
#include "Ray.h"
#include "Sphere.h"
#include "Vec3.h"
#include <fstream>

using namespace raytracer;

Color background(const Ray& ray) {
    auto startColor = Color(1.0, 1.0, 1.0);
    auto endColor = Color(0.5, 0.7, 1.0);

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

Color rayColor(const Ray& ray, const Hittable& hittable) {
    auto minDistance = 0.0;
    auto maxDistance = 1000.0;

    auto hitRecord = hittable.hit(ray, minDistance, maxDistance);
    if (hitRecord.has_value()) {
        auto normal = hitRecord.value().normal;
        return 0.5 * (normal + Color(1, 1, 1));
    }

    return background(ray);
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

    // Objects in our scene
    Hittables objects;
    auto sphere = std::make_shared<Sphere>(Point3(0, 0, -1), 0.5);
    objects.add(sphere);
    auto floor = std::make_shared<Sphere>(Point3(0, -100.5, -1), 100.0);
    objects.add(floor);

    filestream << "P3\n";
    filestream << width << " " << height << "\n";
    filestream << 255 << "\n";

    for (int y = height - 1; y >= 0; --y) {
        for (auto x = 0; x < width; x++) {
            auto u = static_cast<double>(x) / (width - 1);
            auto v = static_cast<double>(y) / (height - 1);

            auto direction = lowerLeftCorner + u * horizontal + v * vertical - origin;
            direction.normalize();

            auto ray = Ray(origin, direction);
            auto color = rayColor(ray, objects);
            writeColor(filestream, color);
        }
    }

    filestream.close();

    return 0;
}
