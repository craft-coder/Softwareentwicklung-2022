#include "Hittables.h"
#include "Lambertian.h"
#include "Metal.h"
#include "Random.h"
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
    // gamma-correct for gamma=2.0.
    auto r = std::sqrt(color.getX());
    auto g = std::sqrt(color.getY());
    auto b = std::sqrt(color.getZ());

    auto red = static_cast<int>(255.999 * r);
    auto green = static_cast<int>(255.999 * g);
    auto blue = static_cast<int>(255.999 * b);

    filestream << red << " " << green << " " << blue << "\n";
}

Color rayColor(const Ray& ray, const Hittable& hittable, int depth) {
    // If we've exceeded the ray bounce limit, no more light is gathered.
    if (depth <= 0) {
        return Color(0, 0, 0);
    }

    auto minDistance = 0.001;
    auto maxDistance = 1000.0;

    auto hitRecord = hittable.hit(ray, minDistance, maxDistance);
    if (!hitRecord.has_value()) { // Did we hit anything?
        return background(ray);
    }

    auto hit = hitRecord.value();
    if (hit.material == nullptr) { // Check for nullptr
        return Color(0, 0, 0);
    }

    Ray scattered;
    Color attenuation;
    auto isScattering = hit.material->scatter(ray, hit, attenuation, scattered);
    if (!isScattering) { // Does the material scatter?
        return Color(0, 0, 0);
    }

    return attenuation * rayColor(scattered, hittable, depth - 1);
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

    auto maxDepth = 50;
    auto samplesPerPixel = 100;

    auto origin = Point3(0.0, 0.0, 0.0);
    auto horizontal = Vec3(viewportWidth, 0.0, 0.0);
    auto vertical = Vec3(0.0, viewportHeight, 0.0);
    auto lowerLeftCorner = origin - Vec3(0.0, 0.0, focalLength) - horizontal / 2.0 - vertical / 2.0;

    // Materials
    auto red = std::make_shared<Lambertian>(Color(0.9, 0.1, 0.1));
    auto yellow = std::make_shared<Lambertian>(Color(0.9, 0.9, 0.1));
    auto metal = std::make_shared<Metal>(Color(0.8, 0.8, 0.8));
    auto gray = std::make_shared<Lambertian>(Color(0.5, 0.5, 0.5));

    // Objects in our scene
    Hittables objects;
    auto sphere = std::make_shared<Sphere>(Point3(-0.3, 0, -1.3), 0.5, red);
    objects.add(sphere);
    auto metalSphere = std::make_shared<Sphere>(Point3(1, 0, -1.5), 0.5, metal);
    objects.add(metalSphere);
    auto smallBall = std::make_shared<Sphere>(Point3(0.2, -0.3, -0.9), 0.2, yellow);
    objects.add(smallBall);
    auto floor = std::make_shared<Sphere>(Point3(0, -100.5, -1), 100.0, gray);
    objects.add(floor);

    filestream << "P3\n";
    filestream << width << " " << height << "\n";
    filestream << 255 << "\n";

    for (int y = height - 1; y >= 0; --y) {
        for (auto x = 0; x < width; x++) {

            Color color(0, 0, 0);
            for (auto sample = 0; sample < samplesPerPixel; sample++) {
                auto u = (x + randomDouble(0.0, 1.0)) / (width - 1);
                auto v = (y + randomDouble(0.0, 1.0)) / (height - 1);

                auto direction = lowerLeftCorner + u * horizontal + v * vertical - origin;
                direction.normalize();

                auto ray = Ray(origin, direction);
                color = color + rayColor(ray, objects, maxDepth);
            }
            color = color / samplesPerPixel;

            writeColor(filestream, color);
        }
    }

    filestream.close();

    return 0;
}
