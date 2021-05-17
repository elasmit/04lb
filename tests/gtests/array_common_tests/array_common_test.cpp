#include "gtest\gtest.h"
#include "array_common.hpp"
#include <vector>

TEST(GCommonTestSuite, SumOfArray)
{
    std::vector<int> input1{2, 3, 5};
    EXPECT_EQ(arrays::sum(input1), 10);
    std::vector<float> input2 = {2.1, 3.1, 5.1};
    EXPECT_FLOAT_EQ(arrays::sum(input2), 10.3);
    std::vector<double> input3 = {2.1, 3.1, 5.1};
    EXPECT_DOUBLE_EQ(arrays::sum(input3), 10.3);

}

TEST(GCommonTestSuite, ArrayToString)
{
    std::vector<int> input1{2, 3, 5};
    EXPECT_EQ(arrays::to_str(input1), "[2, 3, 5]");
}