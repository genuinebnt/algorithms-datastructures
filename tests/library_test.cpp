#include <library.h>

#include <gtest/gtest.h>

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


TEST(testtrue, hello) {
    ASSERT_EQ(hello(), true);
}