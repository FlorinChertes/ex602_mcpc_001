#include "sum_integers.hpp"

#include "gtest/gtest.h"

#include<numeric>
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

TEST(example, use_lambda_004)
{
	auto integers = std::vector<int>{ 1, -2, 3, -4, 5 };

	auto lsum = [](auto const s, auto const n) { return s + n; };

	auto sum = std::accumulate(std::begin(integers), std::end(integers), 0, lsum);

	ASSERT_EQ(sum, 3);
}

TEST(example, use_lambda_005)
{
	auto test_elements = std::vector<std::string>{ "hello", " ", "world", "!"};

	auto lsum = [](auto const s, auto const n) { return s + n; };

	auto sum = std::accumulate(std::begin(test_elements), std::end(test_elements), std::string(), lsum);

	int a = 1;
	int b = 2;


	if (a = 1)
	{
		b = 3;
	}
	ASSERT_EQ(b, 3);

	ASSERT_EQ(sum, std::string("hello world!"));
}
