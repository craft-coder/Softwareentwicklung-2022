#include "Ray.h"

namespace raytracer {

Ray::Ray(const Point3& origin, const Vec3& direction)
    : origin_(origin)
    , direction_(direction) {
}

Point3 Ray::getOrigin() const {
    return origin_;
}

Vec3 Ray::getDirection() const {
    return direction_;
}

Point3 Ray::at(double t) const {
    return origin_ + t * direction_;
}

}