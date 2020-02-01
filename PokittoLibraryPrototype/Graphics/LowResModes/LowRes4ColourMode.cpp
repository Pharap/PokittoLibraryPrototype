#include "LowRes4ColourMode.h"

using GraphicsMode = LowRes4ColourMode;

void GraphicsMode::fill(IndexType index)
{
	const ByteType maskedIndex = (index & indexMask);
	const ByteType value = (maskedIndex << 6) | (maskedIndex << 4) | (maskedIndex << 2) | (maskedIndex << 0);
	GraphicsMode::buffer.fill(value);
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
	
	const std::size_t xx = static_cast<std::size_t>(x);
	const std::size_t yy = static_cast<std::size_t>(y);

	// Values larger than the width or height are offscreen
	if((xx >= bufferWidth) || (yy >= bufferHeight))
		return;

	GraphicsMode::setPixelUnsafe(xx, yy, colourIndex);
}

void GraphicsMode::setPixelUnsafe(std::size_t x, std::size_t y, IndexType colourIndex)
{
	const std::size_t xIndex = (x / pixelsPerByte);
	const std::size_t xOffset = (x % pixelsPerByte);
	const std::size_t pixelShift = (xOffset * bitsPerPixel);
	const std::size_t bufferIndex = ((y * bufferHeight) + xIndex);

	GraphicsMode::buffer[bufferIndex] &= static_cast<ByteType>(~(IndexMask << pixelShift));
	GraphicsMode::buffer[bufferIndex] |= static_cast<ByteType>(((colourIndex & indexMask) << pixelShift));
}

bool GraphicsMode::tryGetPixel(int x, int y, IndexType & colourIndex) const
{
	// Negative values are offscreen
	if((x < 0) || (y < 0))
		return false;
	
	const std::size_t xx = static_cast<std::size_t>(x);
	const std::size_t yy = static_cast<std::size_t>(y);

	// Values larger than the width or height are offscreen
	if((xx >= bufferWidth) || (yy >= bufferHeight))
		return false;

	colourIndex = GraphicsMode::getPixelUnsafe(xx, yy);
	return true;
}

IndexType GraphicsMode::getPixelUnsafe(std::size_t x, std::size_t y)
{
	const std::size_t xIndex = (x / pixelsPerByte);
	const std::size_t xOffset = (x % pixelsPerByte);
	const std::size_t pixelShift = (xOffset * bitsPerPixel);
	const std::size_t bufferIndex = ((y * bufferHeight) + xIndex);

	return static_cast<IndexType>((GraphicsMode::buffer[bufferIndex] >> pixelShift) & indexMask);
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
		visbleHeight = height - absY;

		// Clamp y to the edge of the screen
		clampedY = 0;
	}
	
	const std::size_t clampedX = static_cast<std::size_t>(x);
	GraphicsMode::drawVerticalLineUnsafe(clampedX, clampedY, visibleHeight, colourIndex);
}

void GraphicsMode::drawVerticalLineUnsafe(std::size_t x, std::size_t y, std::size_t height, IndexType colourIndex)
{
	const std::size_t xIndex = (x / pixelsPerByte);
	const std::size_t xOffset = (x % pixelsPerByte);
	const std::size_t pixelShift = (xOffset * bitsPerPixel);

	for(std::size_t i = 0; i < height; ++i)
	{
		const std::size_t bufferIndex = ((y + i) * bufferHeight) + xIndex);

		GraphicsMode::buffer[bufferIndex] &= static_cast<ByteType>(~(IndexMask << pixelShift));
		GraphicsMode::buffer[bufferIndex] |= static_cast<ByteType>(((colourIndex & indexMask) << pixelShift));
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
		visbleWidth = width - absX;

		// Clamp x to the edge of the screen
		clampedX = 0;
	}
	
	const std::size_t clampedY = static_cast<std::size_t>(x);
	GraphicsMode::drawHorizontalLineUnsafe(clampedX, clampedY, visibleWidth, colourIndex);
}

void GraphicsMode::drawHorizontalLineUnsafe(std::size_t x, std::size_t y, std::size_t width, IndexType colourIndex)
{
	// TODO: Implement this
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
	// TODO: Implement this
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
	// TODO: Implement this
}

void GraphicsMode::drawBitmap(int x, int y, const ByteType bitmap[])
{
	// TODO: Implement this
}

void GraphicsMode::drawBitmap(int x, int y, const ByteType bitmap[], std::size_t frameIndex)
{
	// TODO: Implement this
}