#pragma once
#include "Hittable.h"

namespace raytracer {

class Sphere : public Hittable {
  public:
    Sphere() = default;
    Sphere(Point3 center, double radius);

    std::optional<HitRecord> hit(const Ray& ray, double tMin, double tMax) const override;

  private:
    Point3 center_;
    double radius_;
};

}