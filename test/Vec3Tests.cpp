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

TEST(Vec3, lengthOfVector) {
    auto vec = Vec3(1.0, 1.0, 1.0);

    auto length = vec.length();

    auto expectedValue = 1.732;
    ASSERT_NEAR(length, expectedValue, 0.001);
}

TEST(Vec3, addingTwoVectors) {
    auto v1 = Vec3{1.0, 2.0, 3.0};
    auto v2 = Vec3{4.0, 1.0, 0.0};

    auto v3 = v1 + v2;

    ASSERT_NEAR(v3.getX(), 5.0, 0.0001);
    ASSERT_NEAR(v3.getY(), 3.0, 0.0001);
    ASSERT_NEAR(v3.getZ(), 3.0, 0.0001);
}