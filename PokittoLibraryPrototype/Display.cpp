#include "Display.h"

#include "Pins.h"

void Display::fill(RGB565 value)
{
	Display::fill(value.getPackedValue());
};

void Display::fill(std::uint16_t value)
{
};

void Display::clear()
{
	Display::fill(0x0000);
};