#include "Vec3.h"
#include <gtest/gtest.h>

using namespace raytracer;

TEST(Vec3, DefaultConstruction_AllValuesAreZero) {
    auto vec = Vec3();

    auto x = vec.getX();
    auto y = vec.getY();
    auto z = vec.getZ();
    
    ASSERT_NEAR(x, 0.0, 0.0001);
    ASSERT_NEAR(y, 0.0, 0.0001);
    ASSERT_NEAR(z, 0.0, 0.0001);
}

TEST(Vec3, ArgumentConstruction_AllValuesAreAsExpected) {
    auto vec = Vec3(1.0, 2.0, 3.0);

    auto x = vec.getX();
    auto y = vec.getY();
    auto z = vec.getZ();
    
    ASSERT_NEAR(x, 1.0, 0.0001);
    ASSERT_NEAR(y, 2.0, 0.0001);
    ASSERT_NEAR(z, 3.0, 0.0001);
}
