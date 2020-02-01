#pragma once

#include "Buttons.h"

namespace Pokitto
{
	class ButtonStates
	{
	private:
		Buttons buttons;

	public:
		constexpr ButtonStates() :
			buttons{Buttons::None}
		{
		}

		constexpr ButtonStates(Buttons buttons) :
			buttons{buttons}
		{
		}

		constexpr bool isPressed(Button button) const
		{
			using underlying_type = typename std::underlying_type<Button>::type;
			return ((this->buttons & static_cast<Buttons>(1 << static_cast<underlying_type>(button))) != Buttons::None);
		}

		constexpr bool areAnyPressed(Buttons buttons) const
		{
			return ((this->buttons & buttons) != Buttons::None);
		}

		constexpr bool areAllPressed(Buttons buttons) const
		{
			return ((this->buttons & buttons) == buttons);
		}

		constexpr bool areAnyReleased(Buttons buttons) const
		{
			return ((this->buttons & buttons) != buttons);
		}

		constexpr bool areAllReleased(Buttons buttons) const
		{
			return ((this->buttons & buttons) == Buttons::None);
		}
	};
}