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
    return std::sqrt(lengthSquared());
}

double Vec3::lengthSquared() const {
    return x_ * x_ + y_ * y_ + z_ * z_;
}

void Vec3::normalize() {
    auto l = length();
    x_ = x_ / l;
    y_ = y_ / l;
    z_ = z_ / l;
}

Vec3 operator+(const Vec3& a, const Vec3& b) {
    auto x = a.getX() + b.getX();
    auto y = a.getY() + b.getY();
    auto z = a.getZ() + b.getZ();

    auto result = Vec3(x, y, z);
    return result;
}

Vec3 operator-(const Vec3& a, const Vec3& b) {
    auto x = a.getX() - b.getX();
    auto y = a.getY() - b.getY();
    auto z = a.getZ() - b.getZ();

    auto result = Vec3(x, y, z);
    return result;
}

Vec3 operator*(double v, const Vec3& vec) {
    auto x = v * vec.getX();
    auto y = v * vec.getY();
    auto z = v * vec.getZ();

    auto result = Vec3(x, y, z);
    return result;
}
Vec3 operator/(const Vec3& vec, double v) {
    return (1.0 / v) * vec;
}

Vec3 operator*(const Vec3& u, const Vec3& v) {
    return Vec3(u.getX() * v.getX(), u.getY() * v.getY(), u.getZ() * v.getZ());
}

double dot(const Vec3& u, const Vec3& v) {
    return u.getX() * v.getX() + u.getY() * v.getY() + u.getZ() * v.getZ();
}

}
