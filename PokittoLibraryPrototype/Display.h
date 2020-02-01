#pragma once

#include <cstddef>
#include <cstdint>

#include "RGB565.h"

namespace Pokitto
{
	/// This non-instantiable class implements direct screen drawing using raw packed RGB565 values.
	/// It is intended to be used as a basis for implementing other higher-level screen modes.
	class Display
	{
	public:
		/// The Pokitto's screen width.
		static constexpr std::size_t screenWidth = 220;

		/// The Pokitto's screen height.
		static constexpr std::size_t screenHeight = 176;

		/// The number of pixels in the screen.
		static constexpr std::size_t screenSize = screenWidth * screenHeight;

	public:
		/// The constructor is explicitly delected to prevent instatiation.
		///
		/// This is because all the functions of this class are static functions,
		/// which are intended to be called as static functions from the class type itself.
		Display() = delete;

	public:
		/// Gets the Pokitto's screen width.
		///
		/// This primarily exists to maintain a compatible API with the various screen mode types.
		static constexpr std::size_t getWidth() { return screenWidth; }

		/// Gets the Pokitto's screen height.
		///
		/// This primarily exists to maintain a compatible API with the various screen mode types.
		static constexpr std::size_t getHeight() { return screenHeight; }

		/// Fills the Pokitto's screen with the specified packed RGB565 value.
		static void fill(RGB565 value);

		/// Fills the Pokitto's screen with the specified packed RGB565 value.
		static void fill(std::uint16_t value);

		/// Fills the Pokitto's screen with the colour black.
		///
		/// Calling this is equivalent to calling `fill` with a value of `0x0000` in packed RGB565 format.
		static void clear();
	};
}