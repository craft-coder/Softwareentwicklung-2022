#pragma once

namespace raytracer {
class Vec3 {
  public:
    Vec3() = default;
    Vec3(double x, double y, double z);

    double getX() const;
    double getY() const;
    double getZ() const;

  private:
    double x_ = 0.0;
    double y_ = 0.0;
    double z_ = 0.0;
};
} // namespace raytracer
