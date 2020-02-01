#pragma once

#include <cstdint>

#include "../RGB565.h"

namespace Pokitto
{
	namespace Palettes
	{
		constexpr std::uint8_t mono4Step = (256 / (4 - 1));

		constexpr RGB565 mono4[4]
		{
			// 0 - Black
			RGB565::createGrey(mono4Step * 0),

			// 1 - Dark Grey
			RGB565::createGrey(mono4Step * 1),

			// 2 - Light Grey
			RGB565::createGrey(mono4Step * 2),

			// 3 - White
			RGB565::createGrey(mono4Step * 3),
		};

		constexpr std::uint8_t mono16Step = (256 / (16 - 1));

		constexpr RGB565 mono16[16]
		{
			// 0-3 - Black
			RGB565::createGrey(mono16Step * 0),
			RGB565::createGrey(mono16Step * 1),
			RGB565::createGrey(mono16Step * 2),
			RGB565::createGrey(mono16Step * 3),

			// 4-7 - Dark Grey
			RGB565::createGrey(mono16Step * 4),
			RGB565::createGrey(mono16Step * 5),
			RGB565::createGrey(mono16Step * 6),
			RGB565::createGrey(mono16Step * 7),

			// 8-B - Light Grey
			RGB565::createGrey(mono16Step * 8),
			RGB565::createGrey(mono16Step * 9),
			RGB565::createGrey(mono16Step * 10),
			RGB565::createGrey(mono16Step * 11),

			// C-F - White
			RGB565::createGrey(mono16Step * 12),
			RGB565::createGrey(mono16Step * 13),
			RGB565::createGrey(mono16Step * 14),
			RGB565::createGrey(mono16Step * 15),
		};
	}
}