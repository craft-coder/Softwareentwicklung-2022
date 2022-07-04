#pragma once
#include "Hittable.h"
#include <vector>
#include <memory>

namespace raytracer {

class Hittables : public Hittable {
public:
    
    std::optional<HitRecord> hit(const Ray& ray, double tMin, double tMax) const override;
    
    void add(std::shared_ptr<Hittable> object);

private:
    std::vector<std::shared_ptr<Hittable>> objects_;
};

}