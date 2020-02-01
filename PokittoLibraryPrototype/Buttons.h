#pragma once

#include <cstddef>
#include <cstdint>
#include <type_traits>

namespace Pokitto
{
	namespace ButtonIndices
	{
		constexpr std::size_t leftIndex = 0;
		constexpr std::size_t upIndex = 1;
		constexpr std::size_t rightIndex = 2;
		constexpr std::size_t downIndex = 3;
		constexpr std::size_t aIndex = 4;
		constexpr std::size_t bIndex = 5;
		constexpr std::size_t cIndex = 6;
	}

	constexpr std::size_t buttonCount = 7;

	enum class Button
	{
		Left = ButtonIndices::leftIndex,
		Up = ButtonIndices::upIndex,
		Right = ButtonIndices::rightIndex,
		Down = ButtonIndices::downIndex,
		A = ButtonIndices::aIndex,
		B = ButtonIndices::bIndex,
		C = ButtonIndices::cIndex,
	};

	enum class Buttons
	{
		None = 0,
		Left = (1 << ButtonIndices::leftIndex),
		Up = (1 << ButtonIndices::upIndex),
		Right = (1 << ButtonIndices::rightIndex),
		Down = (1 << ButtonIndices::downIndex),
		A = (1 << ButtonIndices::aIndex),
		B = (1 << ButtonIndices::bIndex),
		C = (1 << ButtonIndices::cIndex),
	};

	/// Overload of the bitwise-or operator (`|`), used to combine `Buttons`.
	constexpr Buttons operator |(Buttons left, Buttons right)
	{
		using underlying_type = typename std::underlying_type<Buttons>::type;

		return static_cast<Buttons>(static_cast<underlying_type>(left) | static_cast<underlying_type>(right));
	}

	/// Overload of the bitwise-or-assignment operator (`|=`), used to combine `Buttons`.
	inline Buttons & operator |=(Buttons & left, Buttons right)
	{
		left = (left | right);
		return left;
	}

	/// Overload of the bitwise-and operator (`&`), used to isolate `Buttons`.
	constexpr Buttons operator &(Buttons left, Buttons right)
	{
		using underlying_type = typename std::underlying_type<Buttons>::type;

		return static_cast<Buttons>(static_cast<underlying_type>(left) & static_cast<underlying_type>(right));
	}

	/// Overload of the bitwise-and-assignment operator (`&=`), used to isolate `Buttons`.
	inline Buttons & operator &=(Buttons & left, Buttons right)
	{
		left = (left & right);
		return left;
	}

	/// Overload of the bitwise-xor operator (`^`), used to toggle `Buttons`.
	constexpr Buttons operator ^(Buttons left, Buttons right)
	{
		using underlying_type = typename std::underlying_type<Buttons>::type;

		return static_cast<Buttons>(static_cast<underlying_type>(left) ^ static_cast<underlying_type>(right));
	}

	/// Overload of the bitwise-xor-assignment operator (`^=`), used to toggle `Buttons`.
	inline Buttons & operator ^=(Buttons & left, Buttons right)
	{
		left = (left ^ right);
		return left;
	}
}