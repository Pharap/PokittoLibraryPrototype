#pragma once

#include "../RGB565.h"

namespace Pokitto
{
	namespace Palettes
	{
		constexpr RGB565 pico8[16]
		{
			// 0 - Black
			RGB565::fromRGB(0, 0, 0),

			// 1 - Dark Blue
			RGB565::fromRGB(29, 43, 83),

			// 2 - Dark Purple
			RGB565::fromRGB(126, 37, 83),

			// 3 - Dark Green
			RGB565::fromRGB(0, 135, 81),

			// 4 - Brown
			RGB565::fromRGB(171, 82, 54),

			// 5 - Dark Grey
			RGB565::fromRGB(95, 87, 79),

			// 6 - Light Grey
			RGB565::fromRGB(194, 195, 199),

			// 7 - White
			RGB565::fromRGB(255, 241, 232),

			// 8 - Red
			RGB565::fromRGB(255, 0, 77),
			
			// 9 - Orange
			RGB565::fromRGB(255, 163, 0),

			// A - Yellow
			RGB565::fromRGB(255, 236, 39),

			// B - Green
			RGB565::fromRGB(0, 228, 54),

			// C - Blue
			RGB565::fromRGB(41, 173, 255),

			// D - Indigo
			RGB565::fromRGB(131, 118, 156),

			// E - Pink
			RGB565::fromRGB(255, 119, 168),

			// F - Peach
			RGB565::fromRGB(255, 204, 170),
		};
	}
}