#include "sum_integers.hpp"

#include "gtest/gtest.h"

#include <vector>

int main(int argc, char **argv) 
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(example, use_lambda_001)
{
	auto integers = std::vector<int>{ 1, -2, 3, -4, 5 };

	auto positives = std::count_if(std::begin(integers),
		std::end(integers),
		[](int const n) {return n > 0; });

	ASSERT_EQ(positives, 3);
}

TEST(example, use_lambda_002)
{
	auto integers = std::vector<int>{ 1, -2, 3, -4, 5 };
	auto is_positive = [](int const n) {return n > 0; };

	auto positives = std::count_if(std::begin(integers),
		std::end(integers),
		is_positive);

	ASSERT_EQ(positives, 3);
}

TEST(example, use_lambda_003)
{
	auto integers = std::vector<int>{ 1, -2, 3, -4, 5 };

	auto positives = std::count_if(std::begin(integers),
		std::end(integers),
		[](auto const n) {return n > 0; });

	ASSERT_EQ(positives, 3);
}

