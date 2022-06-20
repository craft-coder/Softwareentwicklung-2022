#pragma once

namespace raytracer {
class Vec3 {
  public:
    Vec3() = default;
    Vec3(double x, double y, double z);

    double getX() const;
    double getY() const;
    double getZ() const;

    double length() const;

    void normalize();

  private:
    double x_ = 0.0;
    double y_ = 0.0;
    double z_ = 0.0;
};

Vec3 operator+(const Vec3& a, const Vec3& b);
Vec3 operator-(const Vec3& a, const Vec3& b);
Vec3 operator*(double v, const Vec3& a);
Vec3 operator/(const Vec3& a, double v);

using Point3 = Vec3;
using Color = Vec3;

}
