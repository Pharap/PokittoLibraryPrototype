#include "LowRes256ColourMode.h"

#include <algorithm>
#include <cstdlib>

using GraphicsMode = LowRes256ColourMode;

void GraphicsMode::fill(IndexType colourIndex)
{
	GraphicsMode::buffer.fill(colourIndex);
};

void GraphicsMode::clear()
{
	GraphicsMode::buffer.fill(0);
};

void GraphicsMode::setPixel(int x, int y, IndexType colourIndex)
{
	// Negative values are offscreen
	if((x < 0) || (y < 0))
		return;
	
	const std::size_t xi = static_cast<std::size_t>(x);
	const std::size_t yi = static_cast<std::size_t>(y);

	// Values larger than the width or height are offscreen
	if((xi >= bufferWidth) || (yi >= bufferHeight))
		return;

	GraphicsMode::setPixelUnsafe(xi, yi, colourIndex);
}

void GraphicsMode::setPixelUnsafe(std::size_t x, std::size_t y, IndexType colourIndex)
{
	const std::size_t xIndex = (x / pixelsPerByte);
	const std::size_t bufferIndex = ((y * bufferHeight) + xIndex);

	GraphicsMode::buffer[bufferIndex] = colourIndex;
}

bool GraphicsMode::tryGetPixel(int x, int y, IndexType & colourIndex) const
{
	// Negative values are offscreen
	if((x < 0) || (y < 0))
		return false;
	
	const std::size_t xi = static_cast<std::size_t>(x);
	const std::size_t yi = static_cast<std::size_t>(y);

	// Values larger than the width or height are offscreen
	if((xi >= bufferWidth) || (yi >= bufferHeight))
		return false;

	colourIndex = GraphicsMode::getPixelUnsafe(xi, yi);
	return true;
}

IndexType GraphicsMode::getPixelUnsafe(std::size_t x, std::size_t y)
{
	const std::size_t xIndex = (x / pixelsPerByte);
	const std::size_t bufferIndex = ((y * bufferHeight) + xIndex);

	return static_cast<IndexType>(GraphicsMode::buffer[bufferIndex]);
}

void GraphicsMode::drawVerticalLine(int x, int y, std::size_t height, IndexType colourIndex)
{
	// A negative x means the line is offscreen.
	if(x < 0)
		return;

	// A height of 0 means the line shouldn't be drawn.
	if(height == 0)
		return;

	std::size_t visibleHeight = height;
	std::size_t clampedY = static_cast<std::size_t>(y);

	// If y is negative
	if(y < 0)
	{
		// Take the absolute value of y, i.e. abs(y)
		const std::size_t absY = static_cast<std::size_t>(-y);

		// If abs(y) is greater than the height of the line
		// then the line is offscreen
		if(absY > height)
			return;

		// Subtract the number of offscreen pixels
		visbleHeight = (height - absY);

		// Clamp y to the edge of the screen
		clampedY = 0;
	}
	
	const std::size_t clampedX = static_cast<std::size_t>(x);
	GraphicsMode::drawVerticalLineUnsafe(clampedX, clampedY, visibleHeight, colourIndex);
}

void GraphicsMode::drawVerticalLineUnsafe(std::size_t x, std::size_t y, std::size_t height, IndexType colourIndex)
{
	for(std::size_t yOffset = 0; yOffset < height; ++yOffset)
	{
		const std::size_t bufferIndex = (((y + yOffset) * bufferHeight) + x);

		GraphicsMode::buffer[bufferIndex] = colourIndex;
	}
}

void GraphicsMode::drawHorizontalLine(int x, int y, std::size_t width, IndexType colourIndex)
{
	// A negative y means the line is offscreen.
	if(y < 0)
		return;

	// A width of 0 means the line shouldn't be drawn.
	if(width == 0)
		return;

	std::size_t visibleWidth = width;
	std::size_t clampedX = static_cast<std::size_t>(x);

	// If x is negative
	if(x < 0)
	{
		// Take the absolute value of x, i.e. abs(x)
		const std::size_t absY = static_cast<std::size_t>(-x);

		// If abs(x) is greater than the width of the line
		// then the line is offscreen
		if(absX > width)
			return;

		// Subtract the number of offscreen pixels
		visbleWidth = (width - absX);

		// Clamp x to the edge of the screen
		clampedX = 0;
	}
	
	const std::size_t clampedY = static_cast<std::size_t>(x);
	GraphicsMode::drawHorizontalLineUnsafe(clampedX, clampedY, visibleWidth, colourIndex);
}

void GraphicsMode::drawHorizontalLineUnsafe(std::size_t x, std::size_t y, std::size_t width, IndexType colourIndex)
{
	for(std::size_t xOffset = 0; xOffset < width; ++xOffset)
	{
		const std::size_t bufferIndex = ((y * bufferHeight) + (x + xOffset));

		GraphicsMode::buffer[bufferIndex] = colourIndex;
	}
}

void GraphicsMode::drawRectangle(int x, int y, std::size_t width, std::size_t height, IndexType colourIndex)
{
	// TODO: Optimise this
	GraphicsMode::drawHorizontalLine(x, y, width, colourIndex);
	GraphicsMode::drawHorizontalLine(x, (y + static_cast<int>(height - 1)), width, colourIndex);
	GraphicsMode::drawVerticalLine(x, y, height, colourIndex);
	GraphicsMode::drawVerticalLine((x + static_cast<int>(width - 1)), y, height, colourIndex);
}

void GraphicsMode::fillRectangle(int x, int y, std::size_t width, std::size_t height, IndexType colourIndex)
{
	// A width of 0 means the rectangle shouldn't be drawn.
	if(width == 0)
		return;

	// A height of 0 means the rectangle shouldn't be drawn.
	if(height == 0)
		return;

	// If the rectangle width is greater than the display width,
	// shorten the rectangle width to be equal to the display width.
	std::size_t visibleWidth = std::min<std::size_t>(width, displayWidth);

	std::size_t clampedX = static_cast<std::size_t>(x);

	// If x is negative
	if(x < 0)
	{
		// Take the absolute value of x, i.e. abs(x)
		const std::size_t absY = static_cast<std::size_t>(-x);

		// If abs(x) is greater than the width of the rectangle
		// then the rectangle is offscreen
		if(absX > width)
			return;

		// Subtract the number of offscreen pixels
		visbleWidth -= absX;

		// Clamp x to the edge of the screen
		clampedX = 0;
	}

	// If the rectangle height is greater than the display height,
	// shorten the rectangle height to be equal to the display height.
	std::size_t visibleHeight = std::min<std::size_t>(height, displayHeight);

	std::size_t clampedY = static_cast<std::size_t>(y);

	// If y is negative
	if(y < 0)
	{
		// Take the absolute value of y, i.e. abs(y)
		const std::size_t absY = static_cast<std::size_t>(-y);

		// If abs(y) is greater than the height of the rectangle
		// then the rectangle is offscreen
		if(absY > height)
			return;

		// Subtract the number of offscreen pixels
		visbleHeight -= absY;

		// Clamp y to the edge of the screen
		clampedY = 0;
	}

	// Fill the rectangle pixels
	for(std::size_t yi = 0; yi < visibleHeight; ++yi)
	{
		// Calculate the Y coordinate
		const std::size_t drawY = (clampedY + yi);

		for(std::size_t xi = 0; xi < visibleWidth; ++xi)
		{
			// Calculate the X coordinate
			const std::size_t drawX = (clampedX + xi);

			// Draw the pixel
			setPixelUnsafe(drawX, drawY, colourIndex);
		}
	}
}

void GraphicsMode::drawCircle(int x, int y, std::size_t radius, IndexType colourIndex)
{
	// TODO: Implement this
}

void GraphicsMode::fillCircle(int x, int y, std::size_t radius, IndexType colourIndex)
{
	// TODO: Implement this
}

void GraphicsMode::drawBitmap(int x, int y, std::size_t width, std::size_t height, const ByteType bitmap[])
{
	// TODO: Optimise this

	// A width of 0 means the bitmap shouldn't be drawn.
	if(width == 0)
		return;

	// A height of 0 means the bitmap shouldn't be drawn.
	if(height == 0)
		return;

	std::size_t sourceXStart = 0;
	std::size_t destinationXStart = static_cast<std::size_t>(x);

	// If the image width is greater than the display width,
	// shorten the image width to be equal to the display width.
	std::size_t renderWidth = std::min<std::size_t>(width, displayWidth);

	if(x < 0)
	{
		// Take the absolute value of x, i.e. abs(x)
		const std::size_t absX = static_cast<std::size_t>(-x);

		// If abs(x) is greater than the width of the bitmap
		// then the bitmap is offscreen
		if(absX > width)
			return;

		// Subtract the number of offscreen pixels
		renderWidth -= absX;

		sourceXStart = absX;
		destinationXStart = 0;
	}

	std::size_t sourceYStart = 0;
	std::size_t destinationYStart = static_cast<std::size_t>(y);

	// If the image height is greater than the display height,
	// shorten the image height to be equal to the display height.
	std::size_t renderHeight = std::min<std::size_t>(height, displayHeight);

	if(y < 0)
	{
		// Take the absolute value of y, i.e. abs(y)
		const std::size_t absY = static_cast<std::size_t>(-y);

		// If abs(y) is greater than the height of the bitmap
		// then the bitmap is offscreen
		if(absY > height)
			return;

		// Subtract the number of offscreen pixels
		renderHeight -= absY;

		sourceYStart = absY;
		destinationYStart = 0;
	}

	for(std::size_t yi = 0; yi < renderHeight; ++yi)
	{
		const std::size_t drawY = (destinationYStart + yi);
		const std::size_t sourceY = (sourceYStart + yi);

		for(std::size_t xi = 0; xi < renderWidth; ++xi)
		{
			const std::size_t drawX = (destinationXStart + xi);
			const std::size_t sourceX = (sourceXStart + xi);

			const std::size_t sourceIndex = ((sourceY * width) + sourceX);

			const IndexType colourIndex = static_cast<IndexType>(bitmap[sourceIndex]);

			GraphicsMode::setPixelUnsafe(drawX, drawY, colourIndex);
		}
	}
}

void GraphicsMode::drawBitmap(int x, int y, const ByteType bitmap[])
{
	constexpr std::size_t widthIndex = 0;
	constexpr std::size_t heightIndex = 1;
	constexpr std::size_t dataIndex = 2;

	const std::size_t width = bitmap[widthIndex];
	const std::size_t height = bitmap[heightIndex];

	GraphicsMode::drawBitmap(x, y, width, height, &bitmap[dataIndex]);
}

void GraphicsMode::drawBitmap(int x, int y, const ByteType bitmap[], std::size_t frameIndex)
{
	constexpr std::size_t widthIndex = 0;
	constexpr std::size_t heightIndex = 1;
	constexpr std::size_t dataIndex = 2;
	constexpr std::size_t bitsPerByte = 8;

	const std::size_t width = bitmap[widthIndex];
	const std::size_t height = bitmap[heightIndex];
	const std::size_t frameSize = ((width * height) / (bitsPerByte / Display::m_colordepth));

	GraphicsMode::drawBitmap(x, y, width, height, &bitmap[dataIndex + (frameIndex * frameSize)]);
}