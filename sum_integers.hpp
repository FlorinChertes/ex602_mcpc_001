#pragma once

#include <vector>
#include <tuple>

int sum_integers(const std::vector<int> integers);

template <typename T>
auto add(T value)
{
	return value;
}

template <typename T, typename ... Ts>
T add(T head, Ts ... rest)
{
	return head + add(rest ...);
}

template<typename ... T>
auto make_even_tuple(T... a)
{
	static_assert(sizeof...(a) % 2 == 0, "expect an event number of arguments");
	std::tuple<T ...> t{ a ... };
	return t;
}

template <typename ... T>
int add_to_one_function(T ... args)
{
	return (1 + ... + args);
}


template <typename T>
struct wrapper
{
	T const& value;
};


template <typename T>
constexpr auto operator< (wrapper<T> const& lhs,
	wrapper<T> const& rhs)
{
	return wrapper<T>
	{lhs.value < rhs.value ? lhs.value : rhs.value};
}

template <typename ... T>
constexpr auto min(T&& ... args)
{
	return (wrapper<T>{args} < ...).value;
}

