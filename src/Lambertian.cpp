#include "Lambertian.h"
#include "Hittable.h"
#include "Random.h"

namespace raytracer {

Lambertian::Lambertian(const Color& color)
    : color_(color) {
}

bool Lambertian::scatter(const Ray& in, const HitRecord& hitRecord, Color& attenuation, Ray& scattered) const {
    auto scatterDirection = hitRecord.normal + randomInUnitSphere();

    // Catch degenerate scatter direction
    if (isNearZero(scatterDirection)) {
        scatterDirection = hitRecord.normal;
    }

    scattered = Ray(hitRecord.point, scatterDirection);
    attenuation = color_;
    return true;
}

Vec3 Lambertian::randomInUnitSphere() const {
    while (true) {
        auto x = randomDouble(0.0, 1.0);
        auto y = randomDouble(0.0, 1.0);
        auto z = randomDouble(0.0, 1.0);
        auto p = Vec3(x, y, z);
        if (p.lengthSquared() >= 1) continue;
        return p;
    }
}

bool Lambertian::isNearZero(const Vec3& v) const {
    const auto s = 1e-8;
    return (fabs(v.getX()) < s) && (fabs(v.getY()) < s) && (fabs(v.getZ()) < s);
}

}