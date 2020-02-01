#pragma once

#include <type_traits>

namespace Pokitto
{
	/// Values to be passed to bitmap drawing functions.
	/// These indicate whether a bitmap should be rotated by 90 clockwise, 90 degrees anticlockwise or 180 degrees.
	enum class BitmapRotation
	{
		None = 0,
		Rotate90Clockwise = 1,
		Rotate180 = 2,
		Rotate90AntiClockwise = 3,
	};

	/// The minimum value a `BitmapRotation` can be.
	constexpr BitmapRotation BitmapRotationMin = BitmapRotation::None;

	/// The maximum value a `BitmapRotation` can be.
	constexpr BitmapRotation BitmapRotationMax = BitmapRotation::Rotate90Clockwise;

	/// The number of distinct values a `BitmapRotation` can be.
	constexpr std::size_t BitmapRotationCount = 4;

	/// A convinience function used rotate the `rotation` clockwise.
	constexpr BitmapRotation rotateClockwise(BitmapRotation rotation)
	{
		using underlying_type = typename std::underlying_type<BitmapRotation>::type;
		using unsigned_type = typename std::make_unsigned<underlying_type>::type;
		return static_cast<BitmapRotation>((static_cast<unsigned_type>(rotation) + 1) & 0x03);
	}
	
	/// A convinience function used rotate the `rotation` anticlockwise.
	constexpr BitmapRotation rotateAntiClockwise(BitmapRotation rotation)
	{
		using underlying_type = typename std::underlying_type<BitmapRotation>::type;
		using unsigned_type = typename std::make_unsigned<underlying_type>::type;
		return static_cast<BitmapRotation>((static_cast<unsigned_type>(rotation) - 1) & 0x03);
	}
}