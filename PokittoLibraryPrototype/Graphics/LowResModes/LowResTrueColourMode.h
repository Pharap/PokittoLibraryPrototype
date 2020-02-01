#pragma once

#include <cstddef>
#include <cstdint>
#include <array>
#include <algorithm>

#include "../RGB565.h"

namespace Pokitto
{
	/// A non-instantiable class representing the standard 65536-colour, 16 bits per pixel, 110x88 display mode.
	class LowResTrueColourMode
	{
	public:
		using ByteType = unsigned char;
		using ColourType = RGB565;

	public:
		/// The horizontal resolution of this display mode.
		static constexpr std::size_t displayWidth = (Display::screenWidth / 2);

		/// The vertical resolution of this display mode.
		static constexpr std::size_t displayHeight = (Display::screenHeight / 2);

		/// A static constant indicating that this mode is indexed (i.e. uses a colour palette).
		static constexpr bool isIndexed = false;

		/// The number of colours supported by this display mode.
		static constexpr std::size_t colourCount = 65536;

		/// The number of bits used per pixel.
		static constexpr std::size_t bitsPerPixel = 16;

		/// The width of this display mode's frame buffer.
		static constexpr std::size_t bufferWidth = (displayWidth * 2);

		/// The height of this display mode's frame buffer.
		static constexpr std::size_t bufferHeight = (displayHeight * 2);

		/// The size (in bytes) of this display mode's buffer.
		static constexpr std::size_t bufferSize = (bufferWidth * bufferHeight);

	public:
		/// The frame buffer.
		static std::array<RGB565, bufferSize> buffer;

	public:
		/// The constructor is explicitly delected to prevent instatiation.
		///
		/// This is because all the functions of this class are static functions,
		/// which are intended to be called as static functions from the class type itself.
		LowResTrueColourMode() = delete;

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
		static std::array<RGB565, bufferSize> & getBuffer()
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

		/// Fills the display mode's frame buffer with the specified colour.
		static void fill(RGB565 colour);

		/// Fills the display mode's frame buffer with the colour black.
		///
		/// Calling this is equivalent to calling `fill` with a value of `RGB565(0)`.
		static void clear();

		/// Sets the value at the specified coordinate to the specified colour.
		/// Checks whether the coordinates are on screen before attempting to draw them.
		static void setPixel(int x, int y, RGB565 colour);

		/// Sets the value at the specified coordinate to the specified colour.
		/// Does not perform any bounds checking, it is up to the caller to ensure that the arguments are valid.
		static void setPixelUnsafe(std::size_t x, std::size_t y, RGB565 colour);

		/// Retrieves the colour at the specified coordinate.
		/// Checks whether the coordinates are onscreen before attempting to retrieve the colour.
		///
		/// Returns `true` if the coordinate is onscreen `false` is the coordinate is not onscreen.
		/// `colourIndex` is only assigned to if the coordinate is onscreen.
		static bool tryGetPixel(int x, int y, IndexType & colourIndex);

		/// Retrieves the colour at the specified coordinate.
		/// Does not perform any bounds checking, it is up to the caller to ensure that the arguments are valid.
		static IndexType getPixelUnsafe(std::size_t x, std::size_t y);

		static void drawLine(int x0, int y0, int x1, int y1, RGB565 colour);

		static void drawVerticalLine(int x, int y, std::size_t height, RGB565 colour);
		static void drawVerticalLineUnsafe(std::size_t x, std::size_t y, std::size_t height, RGB565 colour);
		
		static void drawHorizontalLine(int x, int y, std::size_t width, RGB565 colour);
		static void drawHorizontalLineUnsafe(std::size_t x, std::size_t y, std::size_t width, RGB565 colour);
		
		static void drawRectangle(int x, int y, std::size_t width, std::size_t height, RGB565 colour);
		static void fillRectangle(int x, int y, std::size_t width, std::size_t height, RGB565 colour);
		
		static void drawCircle(int x, int y, std::size_t radius, RGB565 colour);
		static void fillCircle(int x, int y, std::size_t radius, RGB565 colour);

		//static void drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, RGB565 colour);
		//static void fillTriangle(int x0, int y0, int x1, int y1, int x2, int y2, RGB565 colour);
		
		//static void drawRoundedRectangle(int x, int y, std::size_t width, std::size_t height, unsigned int radius, RGB565 colour);
		//static void fillRoundedRectangle(int x, int y, std::size_t width, std::size_t height, unsigned int radius, RGB565 colour);

		static void drawBitmap(int x, int y, std::size_t width, std::size_t height, const ByteType bitmap[]);
		static void drawBitmap(int x, int y, const ByteType bitmap[]);
		static void drawBitmap(int x, int y, const ByteType bitmap[], std::size_t frameIndex);

		//static void drawRleBitmap(int x, int y, std::size_t width, std::size_t height, const ByteType bitmap[]);
		//static void drawRleBitmap(int x, int y, const ByteType bitmap[]);
		//static void drawRleBitmap(int x, int y, const ByteType bitmap[], std::size_t frameIndex);

		//static void drawMonochromeBitmap(int x, int y, std::size_t width, std::size_t height, const ByteType bitmap[]);
		//static void drawMonochromeBitmap(int x, int y, const ByteType bitmap[]);
		//static void drawMonochromeBitmap(int x, int y, const ByteType bitmap[], std::size_t frameIndex);

		//static void drawBitmapInterlacedMask(int x, int y, std::size_t width, std::size_t height, const ByteType bitmap[]);
		//static void drawBitmapInterlacedMask(int x, int y, const ByteType bitmap[]);
		//static void drawBitmapInterlacedMask(int x, int y, const ByteType bitmap[], std::size_t frameIndex);

		//static void drawBitmapExternalMask(int x, int y, std::size_t width, std::size_t height, const ByteType bitmap[], const mask[]);
		//static void drawBitmapExternalMask(int x, int y, const ByteType bitmap[], const mask[]);
		//static void drawBitmapExternalMask(int x, int y, const ByteType bitmap[], const mask[], std::size_t frameIndex);
	};
}