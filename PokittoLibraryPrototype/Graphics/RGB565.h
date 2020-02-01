#pragma once

#include <cstdint>

namespace Pokitto
{
	class RGB565
	{
	public:
		using PackedType = std::uint16_t;
		using ChannelType = std::uint8_t;

	private:
		PackedType value;

	public:
		RGB565() = default;

		constexpr RGB565(PackedType packedValue)
			: value { packedValue }
		{
		}

		constexpr ChannelType getRed() const
		{
			return static_cast<ChannelType>((this->value >> redShift) & redMask);
		}

		constexpr ChannelType getGreen() const
		{
			return static_cast<ChannelType>((this->value >> greenShift) & greenMask);
		}

		constexpr ChannelType getBlue() const
		{
			return static_cast<ChannelType>((this->value >> blueShift) & blueMask);
		}

		constexpr PackedType getPackedValue() const
		{
			return this->value;
		}

		static constexpr RGB565 fromRGB(std::uint8_t red, std::uint8_t green, std::uint8_t blue)
		{
			return { packedFromRGB(red, green, blue) };
		}

		static constexpr RGB888 createGrey(std::uint8_t shade)
		{
			return fromRGB(shade, shade, shade);
		}

		static constexpr RGB565 fromPackedValue(PackedType packedValue)
		{
			return { packedValue };
		}

	private:
		static constexpr int redBits = 5;
		static constexpr int greenBits = 6;
		static constexpr int blueBits = 5;

		static constexpr int redShift = (greenBits + blueBits);
		static constexpr int greenShift = blueBits;
		static constexpr int blueShift = 0;

		static constexpr PackedType redMask = ((1 << redBits) - 1);
		static constexpr PackedType greenMask = ((1 << greenBits) - 1);
		static constexpr PackedType blueMask = ((1 << blueBits) - 1);

	private:
		static constexpr PackedType packedFromRGB(std::uint8_t red, std::uint8_t green, std::uint8_t blue)
		{
			return static_cast<PackedType>
			(
				((red & redMask) << redShift) |
				((green & greenMask) << greenShift) |
				((blue & blueMask) << blueShift)
			);
		}
	};
}