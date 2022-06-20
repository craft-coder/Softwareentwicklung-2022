#include "Vec3.h"
#include <cmath>

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

double Vec3::length() const {
    return std::sqrt(x_ * x_ + y_ * y_ + z_ * z_);
}

Vec3 operator+(const Vec3& a, const Vec3& b) {
    auto x = a.getX() + b.getX();
    auto y = a.getY() + b.getY();
    auto z = a.getZ() + b.getZ();

    auto result = Vec3(x, y, z);
    return result;
}

} // namespace raytracer
