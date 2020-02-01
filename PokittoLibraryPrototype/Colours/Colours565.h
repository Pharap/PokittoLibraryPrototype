#pragma once

#include "../RGB565.h"

namespace Pokitto
{
	namespace Colours565
	{
		constexpr RGB565 Black = RGB565::fromRGB(0x00, 0x00, 0x00);
		constexpr RGB565 Grey = RGB565::fromRGB(0x7F, 0x7F, 0x7F);
		constexpr RGB565 White = RGB565::fromRGB(0xFF, 0xFF, 0xFF);

		constexpr RGB565 Red = RGB565::fromRGB(0xFF, 0x00, 0x00);
		constexpr RGB565 Green = RGB565::fromRGB(0x00, 0xFF, 0x00);
		constexpr RGB565 Blue = RGB565::fromRGB(0x00, 0x00, 0xFF);
		
		constexpr RGB565 Magenta = RGB565::fromRGB(0xFF, 0x00, 0xFF);
		constexpr RGB565 Yellow = RGB565::fromRGB(0xFF, 0xFF, 0x00);
		constexpr RGB565 Cyan = RGB565::fromRGB(0x00, 0xFF, 0xFF);

		constexpr RGB565 Grey15 = RGB565::fromRGB(15, 15, 15);
		constexpr RGB565 Grey30 = RGB565::fromRGB(30, 30, 30);
		constexpr RGB565 Grey50 = RGB565::fromRGB(50, 50, 50);
		constexpr RGB565 Grey80 = RGB565::fromRGB(80, 80, 80);
		constexpr RGB565 Grey128 = RGB565::fromRGB(128, 128, 128);
		constexpr RGB565 Grey200 = RGB565::fromRGB(200, 200, 200);
		constexpr RGB565 Grey225 = RGB565::fromRGB(225, 225, 225);
	}
}