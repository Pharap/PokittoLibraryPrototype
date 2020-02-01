#pragma once

namespace Pokitto
{
	namespace Board1
	{
		struct ScreenPins
		{
			ScreenPins() = delete;

			static constexpr int CDPort = 0;
			static constexpr int CDPin = 2;
			static constexpr int CDPinBit = (1 << CDPin);

			static constexpr int WritePort = 1;
			static constexpr int WritePin = 23;
			static constexpr int WritePinBit = (1 << WritePin);

			static constexpr int ReadPort = 1;
			static constexpr int ReadPin = 24;
			static constexpr int ReadPinBit = (1 << ReadPin);

			static constexpr int ResetPort = 1;
			static constexpr int ResetPin = 28;
			static constexpr int ResetPinBit = (1 << ResetPin);
		};
	}
};