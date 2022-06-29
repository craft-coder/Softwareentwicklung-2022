#pragma once
#include "Ray.h"
#include "Vec3.h"
#include <optional>

namespace raytracer {

struct HitRecord {
    Point3 point;
    Vec3 normal;
    double distance;
};

class Hittable {
  public:
    virtual ~Hittable() = default;

    virtual std::optional<HitRecord> hit(const Ray& ray, double tMin, double tMax) const = 0;
};

}