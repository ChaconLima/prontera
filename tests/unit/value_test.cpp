#include <value/value.h>
#include <gtest/gtest.h>


TEST(MultiplyTests, TestIntegerOne_One){
    const auto expected = "test_cmake";
    const auto actual = value::getValue();
    ASSERT_EQ(expected, actual);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}