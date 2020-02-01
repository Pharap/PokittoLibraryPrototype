#pragma once

#include "../RGB565.h"

namespace Pokitto
{
	namespace Palettes
	{
		constexpr RGB565 cga[16]
		{
			// 0 - Black
			RGB565::fromRGB(0x00, 0x00, 0x00),

			// 1 - Blue
			RGB565::fromRGB(0x00, 0x00, 0xAA),

			// 2 - Green
			RGB565::fromRGB(0x00, 0xAA, 0x00),

			// 3 - Cyan
			RGB565::fromRGB(0x00, 0xAA, 0xAA),

			// 4 - Red
			RGB565::fromRGB(0xAA, 0x00, 0x00),

			// 5 - Magenta
			RGB565::fromRGB(0xAA, 0x00, 0xAA),

			// 6 - Brown
			RGB565::fromRGB(0xAA, 0x55, 0x00),

			// 7 - Light Grey
			RGB565::fromRGB(0xAA, 0xAA, 0xAA),

			// 8 - Dark Grey
			RGB565::fromRGB(0x55, 0x55, 0x55),

			// 9 - Light Blue
			RGB565::fromRGB(0x55, 0x55, 0xFF),

			// A - Light Green
			RGB565::fromRGB(0x55, 0xFF, 0x55),

			// B - Light Cyan
			RGB565::fromRGB(0x55, 0xFF, 0xFF),

			// C - Light Red
			RGB565::fromRGB(0xFF, 0x55, 0x55),

			// D - Light Magenta
			RGB565::fromRGB(0xFF, 0x55, 0xFF),

			// E - Yellow
			RGB565::fromRGB(0xFF, 0xFF, 0x55),

			// F - White
			RGB565::fromRGB(0xFF, 0xFF, 0xFF),
		};
	}
}