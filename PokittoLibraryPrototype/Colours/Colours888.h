#pragma once

#include "../RGB888.h"

namespace Pokitto
{
	namespace Colours888
	{
		constexpr RGB888 Black = RGB888::fromRGB(0x00, 0x00, 0x00);
		constexpr RGB888 Grey = RGB888::fromRGB(0x7F, 0x7F, 0x7F);
		constexpr RGB888 White = RGB888::fromRGB(0xFF, 0xFF, 0xFF);

		constexpr RGB888 Red = RGB888::fromRGB(0xFF, 0x00, 0x00);
		constexpr RGB888 Green = RGB888::fromRGB(0x00, 0xFF, 0x00);
		constexpr RGB888 Blue = RGB888::fromRGB(0x00, 0x00, 0xFF);
		
		constexpr RGB888 Magenta = RGB888::fromRGB(0xFF, 0x00, 0xFF);
		constexpr RGB888 Yellow = RGB888::fromRGB(0xFF, 0xFF, 0x00);
		constexpr RGB888 Cyan = RGB888::fromRGB(0x00, 0xFF, 0xFF);

		constexpr RGB888 Grey15 = RGB888::fromRGB(15, 15, 15);
		constexpr RGB888 Grey30 = RGB888::fromRGB(30, 30, 30);
		constexpr RGB888 Grey50 = RGB888::fromRGB(50, 50, 50);
		constexpr RGB888 Grey80 = RGB888::fromRGB(80, 80, 80);
		constexpr RGB888 Grey128 = RGB888::fromRGB(128, 128, 128);
		constexpr RGB888 Grey200 = RGB888::fromRGB(200, 200, 200);
		constexpr RGB888 Grey225 = RGB888::fromRGB(225, 225, 225);
	}
}