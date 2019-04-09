#pragma once

#include <vector>

int sum_integers(const std::vector<int> integers);

template <typename T>
T add(T value)
{
	return value;
}

template <typename T, typename ... Ts>
T add(T head, Ts ... rest)
{
	return head + add(rest ...);
}