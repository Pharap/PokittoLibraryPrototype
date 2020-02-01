#pragma once

#include <cstdint>

namespace Pokitto
{
	class RGB888
	{
	public:
		using PackedType = std::uint32_t;
		using ChannelType = std::uint8_t;

	private:
		ChannelType red;
		ChannelType green;
		ChannelType blue;

	public:
		RGB888() = default;

		constexpr RGB888(PackedType packedValue) :
			red { unpackRed(packedValue) },
			green { unpackGreen(packedValue) },
			blue { unpackBlue(packedValue) }
		{
		}

		constexpr RGB888(std::uint8_t red, std::uint8_t green, std::uint8_t blue) :
			red { red }, green { green }, blue { blue }
		{
		}

		constexpr ChannelType getRed() const
		{
			return this->red;
		}

		constexpr ChannelType getGreen() const
		{
			return this->green;
		}

		constexpr ChannelType getBlue() const
		{
			return this->blue;
		}

		constexpr PackedType getPackedValue() const
		{
			return static_cast<PackedType>
			(
				(this->red << redShift) | (this->green << greenShift) | (this->blue << blueShift)
			);
		}

		static constexpr RGB888 fromRGB(std::uint8_t red, std::uint8_t green, std::uint8_t blue)
		{
			return { red, green, blue };
		}

		static constexpr RGB888 createGrey(std::uint8_t shade)
		{
			return fromRGB(shade, shade, shade);
		}

		static constexpr RGB888 fromPackedValue(PackedType packedValue)
		{
			return { unpackRed(packedValue), unpackGreen(packedValue), unpackBlue(packedValue) };
		}

	private:
		static constexpr int redBits = 8;
		static constexpr int greenBits = 8;
		static constexpr int blueBits = 8;

		static constexpr int redShift = (greenBits + blueBits);
		static constexpr int greenShift = blueBits;
		static constexpr int blueShift = 0;

		static constexpr PackedType redMask = ((1 << redBits) - 1);
		static constexpr PackedType greenMask = ((1 << greenBits) - 1);
		static constexpr PackedType blueMask = ((1 << blueBits) - 1);

	private:
		static constexpr ChannelType unpackRed(PackedType packed)
		{
			return static_cast<ChannelType>((packed & redMask) >> redShift)
		}
		
		static constexpr ChannelType unpackGreen(PackedType packed)
		{
			return static_cast<ChannelType>((packed & greenMask) >> greenShift)
		}
		
		static constexpr ChannelType unpackBlue(PackedType packed)
		{
			return static_cast<ChannelType>((packed & blueMask) >> blueShift)
		}
	};
}