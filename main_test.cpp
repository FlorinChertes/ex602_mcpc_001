#include "sum_integers.hpp"

#include <iostream>
#include <string>
#include <vector>

// we assume all arguments are integers and we sum them up
// for simplicity we do not verify the type of arguments
int main(int argc, char *argv[]) 
{
	std::vector<int> integers;

	for (auto i = 1; i < argc; i++)
	{
		integers.push_back(atoi(argv[i]));
	}

	auto sum = sum_integers(integers);
	std::cout << sum << std::endl;

	return 0;
}
