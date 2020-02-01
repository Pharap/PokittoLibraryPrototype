#pragma once

#include "Buttons.h"

#include <type_traits>

namespace Pokitto
{
	template<typename Counter>
	class ButtonCounters
	{
	public:
		using CounterType = Counter;

	private:
		CounterType counters[buttonCount];

	public:

		void update(Buttons buttons)
		{
			using underlying_type = typename std::underlying_type<Buttons>::type;

			constexpr underlying_type mask = static_cast<underlying_type>(0x01);

			const underlying_type buttonData = static_cast<underlying_type>(buttons);

			for(std::size_t index = 0; index < buttonCount; ++index)
				if(((buttonData >> index) & mask) != 0)
					++counters[index];
		}

		constexpr CounterType getCounterValue(Button button) const
		{
			using underlying_type = typename std::underlying_type<Button>::type;

			return this->counters[static_cast<underlying_type>(button)];
		}
	};
}