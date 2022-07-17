#pragma once
#include "Material.h"

namespace raytracer {

class Lambertian : public Material {
  public:
    Lambertian(const Color& color);

    bool scatter(const Ray& in, const HitRecord& hitRecord, Color& attenuation, Ray& scattered) const override;

  private:
    Vec3 randomInUnitSphere() const;
    bool isNearZero(const Vec3&) const;

    Color color_;
};

}
