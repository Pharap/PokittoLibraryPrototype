#pragma once

#include <cstddef>
#include <cstdint>
#include <array>
#include <algorithm>

#include "../RGB565.h"

namespace Pokitto
{
	/// A non-instantiable class representing the standard 4-colour, 2 bits per pixel, 110x88 display mode.
	class LowRes4ColourMode
	{
	public:
		using IndexType = std::uint_fast8_t;
		using ByteType = unsigned char;

	public:
		/// The horizontal resolution of this display mode.
		static constexpr std::size_t displayWidth = (Display::screenWidth / 2);

		/// The vertical resolution of this display mode.
		static constexpr std::size_t displayHeight = (Display::screenHeight / 2);

		/// A static constant indicating that this mode is indexed (i.e. uses a colour palette).
		static constexpr bool isIndexed = true;

		/// The number of indexed colours supported by this display mode.
		static constexpr std::size_t colourCount = 4;

		/// The number of bits used per pixel.
		static constexpr std::size_t bitsPerPixel = 2;

		/// The number of pixels stored per byte.
		static constexpr std::size_t pixelsPerByte = (8 / bitsPerPixel);

		/// The width of this display mode's frame buffer.
		static constexpr std::size_t bufferWidth = (displayWidth / pixelsPerByte);

		/// The height of this display mode's frame buffer.
		static constexpr std::size_t bufferHeight = displayHeight;

		/// The size (in bytes) of this display mode's buffer.
		static constexpr std::size_t bufferSize = (bufferWidth * bufferHeight);

	private:
		/// The mask used to ensure an index is in the valid index range.
		static constexpr IndexType indexMask = ((1 << bitsPerPixel) - 1);

	public:
		/// The frame buffer.
		static std::array<ByteType, bufferSize> buffer;

		/// The colour palette.
		static std::array<RGB565, colourCount> palette;

	public:
		/// The constructor is explicitly delected to prevent instatiation.
		///
		/// This is because all the functions of this class are static functions,
		/// which are intended to be called as static functions from the class type itself.
		LowRes4ColourMode() = delete;

	public:
		/// Returns the width of the display mode.
		static constexpr std::size_t getWidth()
		{
			return displayWidth;
		}

		/// Returns the height of the display mode.
		static constexpr std::size_t getHeight()
		{
			return displayHeight;
		}

		/// Returns a reference to the display buffer
		static std::array<ByteType, bufferSize> & getBuffer()
		{
			return buffer;
		}

		/// Copies the colour values from the specified array into the colour palette.
		template<std::size_t size>
		void setPalette(RGB565 (&colours)[size])
		{
			constexpr std::size_t limit = (colourCount < size) ? colourCount : size;

			std::copy_n(colours, limit, this->palette.begin());
		}

		/// Fills the display mode's frame buffer with the specified colour index.
		static void fill(IndexType index);

		/// Fills the display mode's frame buffer with colour index 0.
		///
		/// Calling this is equivalent to calling `fill` with a value of `0`.
		static void clear();

		/// Sets the value at the specified coordinate to the specified index.
		/// Checks whether the coordinates are onscreen before attempting to draw them.
		static void setPixel(int x, int y, IndexType colourIndex);

		/// Sets the value at the specified coordinate to the specified index.
		/// Does not perform any bounds checking, it is up to the caller to ensure that the arguments are valid.
		static void setPixelUnsafe(std::size_t x, std::size_t y, IndexType colourIndex);

		/// Retrieves the colour index at the specified coordinate.
		/// Checks whether the coordinates are onscreen before attempting to retrieve the index.
		///
		/// Returns `true` if the coordinate is onscreen `false` is the coordinate is not onscreen.
		/// `colourIndex` is only assigned to if the coordinate is onscreen.
		static bool tryGetPixel(int x, int y, IndexType & colourIndex);

		/// Retrieves the colour index at the specified coordinate.
		/// Does not perform any bounds checking, it is up to the caller to ensure that the arguments are valid.
		static IndexType getPixelUnsafe(std::size_t x, std::size_t y);

		static void drawLine(int x0, int y0, int x1, int y1, IndexType colourIndex);

		static void drawVerticalLine(int x, int y, std::size_t height, IndexType colourIndex);

		static void drawVerticalLineUnsafe(std::size_t x, std::size_t y, std::size_t height, IndexType colourIndex);
		
		static void drawHorizontalLine(int x, int y, std::size_t width, IndexType colourIndex);

		static void drawHorizontalLineUnsafe(std::size_t x, std::size_t y, std::size_t width, IndexType colourIndex);
		
		static void drawRectangle(int x, int y, std::size_t width, std::size_t height, IndexType colourIndex);
		static void fillRectangle(int x, int y, std::size_t width, std::size_t height, IndexType colourIndex);
		
		static void drawCircle(int x, int y, std::size_t radius, IndexType colourIndex);
		static void fillCircle(int x, int y, std::size_t radius, IndexType colourIndex);

		static void drawBitmap(int x, int y, std::size_t width, std::size_t height, const ByteType bitmap[]);
		static void drawBitmap(int x, int y, const ByteType bitmap[]);
		static void drawBitmap(int x, int y, const ByteType bitmap[], std::size_t frameIndex);
	};
}