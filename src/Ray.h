#pragma once
#include "Vec3.h"

namespace raytracer {

class Ray {
public:
    Ray() = default;
    Ray(const Point3& origin, const Vec3& direction);

    Point3 getOrigin() const;
    Vec3 getDirection() const;

    Point3 at(double t) const;

private:
    Point3 origin_;
    Vec3 direction_;
};

}
