#include "Hittables.h"

namespace raytracer {

std::optional<HitRecord> Hittables::hit(const Ray& ray, double tMin, double tMax) const {
    std::optional<HitRecord> result = std::nullopt;
    auto closestSoFar = tMax;

    for (auto object : objects_) {
        auto hitRecord = object->hit(ray, tMin, closestSoFar);
        if (hitRecord.has_value()) {
            result = hitRecord;
            closestSoFar = hitRecord.value().distance;
        }
    }

    return result;
}

void Hittables::add(std::shared_ptr<Hittable> object) {
    objects_.push_back(object);
}

}