#pragma once

#include <type_traits>

namespace Pokitto
{
	/// Flags to be passed to bitmap drawing functions.
	/// These indicate whether a bitmap should be flipped on either the X or Y axis.
	/// The flags can be combined and manipulated with bitwise operators.
	enum class BitmapFlipFlags
	{
		None = 0,
		FlipX = (1 << 0),
		FlipY = (1 << 1),
		FlipXY = (FlipX | FlipY),
	};

	/// Overload of the bitwise-or operator (`|`), used to combine `BitmapFlipFlags`.
	///
	/// This operation is implemented using the `|` operator for the underlying type of `BitmapFlipFlags`
	/// (as determined by `std::underlying_type`).
	/// As such, all the standard rules of the bitwise-or operator remain true.
	constexpr BitmapFlipFlags operator |(BitmapFlipFlags left, BitmapFlipFlags right)
	{
		using underlying_type = typename std::underlying_type<BitmapFlipFlags>::type;

		return static_cast<BitmapFlipFlags>(static_cast<underlying_type>(left) | static_cast<underlying_type>(right));
	}

	/// Overload of the bitwise-or-assignment operator (`|=`), used to combine `BitmapFlipFlags`.
	inline BitmapFlipFlags & operator |=(BitmapFlipFlags & left, BitmapFlipFlags right)
	{
		left = (left | right);
		return left;
	}

	/// Overload of the bitwise-and operator (`&`), used to isolate `BitmapFlipFlags`.
	constexpr BitmapFlipFlags operator &(BitmapFlipFlags left, BitmapFlipFlags right)
	{
		using underlying_type = typename std::underlying_type<BitmapFlipFlags>::type;

		return static_cast<BitmapFlipFlags>(static_cast<underlying_type>(left) & static_cast<underlying_type>(right));
	}

	/// Overload of the bitwise-and-assignment operator (`&=`), used to isolate `BitmapFlipFlags`.
	inline BitmapFlipFlags & operator &=(BitmapFlipFlags & left, BitmapFlipFlags right)
	{
		left = (left & right);
		return left;
	}

	/// Overload of the bitwise-xor operator (`^`), used to toggle `BitmapFlipFlags`.
	constexpr BitmapFlipFlags operator ^(BitmapFlipFlags left, BitmapFlipFlags right)
	{
		using underlying_type = typename std::underlying_type<BitmapFlipFlags>::type;

		return static_cast<BitmapFlipFlags>(static_cast<underlying_type>(left) ^ static_cast<underlying_type>(right));
	}

	/// Overload of the bitwise-xor-assignment operator (`^=`), used to toggle `BitmapFlipFlags`.
	inline BitmapFlipFlags & operator ^=(BitmapFlipFlags & left, BitmapFlipFlags right)
	{
		left = (left ^ right);
		return left;
	}

	/// A convinience function used to flip the `flipFlags` on the X axis.
	///
	/// Note that `flipX` satisfies the following laws:
	/// * `flipX(flipX(flipFlags)) == flipFlags`
	/// * `flipX(BitmapFlipFlags::None) == BitmapFlipFlags::FlipX`
	/// * `flipX(BitmapFlipFlags::FlipX) == BitmapFlipFlags::None`
	constexpr BitmapFlipFlags flipX(BitmapFlipFlags flipFlags)
	{
		return (flipFlags ^ BitmapFlipFlags::FlipX);
	}

	/// A convinience function used to flip the `flipFlags` on the Y axis.
	///
	/// Note that `flipY` satisfies the following laws:
	/// * `flipY(flipY(flipFlags)) == flipFlags`
	/// * `flipY(BitmapFlipFlags::None) == BitmapFlipFlags::FlipY`
	/// * `flipY(BitmapFlipFlags::FlipY) == BitmapFlipFlags::None`
	constexpr BitmapFlipFlags flipY(BitmapFlipFlags flipFlags)
	{
		return (flipFlags ^ BitmapFlipFlags::FlipY);
	}

	/// A convinience function used to test if `flipFlags` is flipped on the X axis.
	///
	/// Note that `isFlippedX` satisfies the following laws:
	/// * `isFlippedX(flipFlags) == (flipFlagsX == (flipFlagsX | BitmapFlipFlags::FlipX))`
	constexpr bool isFlippedX(BitmapFlipFlags flipFlags)
	{
		return ((flipFlags & BitmapFlipFlags::FlipX) != BitmapFlipFlags::None);
	}

	/// A convinience function used to test if `flipFlags` is flipped on the Y axis.
	///
	/// Note that `isFlippedY` satisfies the following laws:
	/// * `isFlippedY(flipFlags) == (flipFlagsY == (flipFlagsY | BitmapFlipFlags::FlipY))`
	constexpr bool isFlippedY(BitmapFlipFlags flipFlags)
	{
		return ((flipFlags & BitmapFlipFlags::FlipY) != BitmapFlipFlags::None);
	}
}