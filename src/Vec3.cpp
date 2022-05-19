#include "Vec3.h"

namespace raytracer {

Vec3::Vec3(double x, double y, double z) {
    x_ = x;
    y_ = y;
    z_ = z;
}

double Vec3::getX() const {
    return x_;
}

double Vec3::getY() const {
    return y_;
}

double Vec3::getZ() const {
    return z_;
}

} // namespace raytracer
