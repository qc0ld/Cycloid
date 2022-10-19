#include "gtest/gtest.h"
#include "cycloid.h"


TEST(Cycloid_test, test_exception) {
    ASSERT_ANY_THROW(CycloidSpace::Cycloid(2, -4));
    ASSERT_ANY_THROW(CycloidSpace::Cycloid(0, 4));
    ASSERT_ANY_THROW(CycloidSpace::Cycloid(99, -100));
    ASSERT_ANY_THROW(CycloidSpace::Cycloid(26, 0));
}

TEST(Cycloid_test, cartesian_coordinates) {
    CycloidSpace::Cycloid a(13, 60);
    EXPECT_DOUBLE_EQ(a.cartesian_coordinates(), 32.851551859017441);
}

TEST(Cycloid_test, radius_of_curvative) {
    CycloidSpace::Cycloid a(10, 80);
    EXPECT_DOUBLE_EQ(a.radius_of_curvature(), 29.804526419173953);
}

TEST(Cycloid_test, lenght) {
    CycloidSpace::Cycloid a1(10, 80);
    EXPECT_DOUBLE_EQ(a1.length(), 80);
    CycloidSpace::Cycloid a2(40, 213);
    EXPECT_DOUBLE_EQ(a2.length(), 320);
    CycloidSpace::Cycloid a3(7, 11);
    EXPECT_DOUBLE_EQ(a3.length(), 56);
}

TEST(Cycloid_test, square) {
    CycloidSpace::Cycloid a1(15, 72);
    EXPECT_DOUBLE_EQ(a1.square(), 2120.5750411731105);
    CycloidSpace::Cycloid a2(7, 121);
    EXPECT_DOUBLE_EQ(a2.square(), 461.81412007769961);
}

TEST(Cycloid_test, square_from_rotation) {
    CycloidSpace::Cycloid a1(22, 31);
    EXPECT_DOUBLE_EQ(a1.square_from_rotation(), 15007.037913265109);
    CycloidSpace::Cycloid a2(12, 41);
    EXPECT_DOUBLE_EQ(a2.square_from_rotation(), 4464.9038419631743);
}

TEST(Cycloid_test, volume_from_rotation) {
    CycloidSpace::Cycloid a1(6, 62);
    EXPECT_NEAR(a1.volume_from_rotation(), a1.simpson_volume_from_rotation(), 1);
}

int test_main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}