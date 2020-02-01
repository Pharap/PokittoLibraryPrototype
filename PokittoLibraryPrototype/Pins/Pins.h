#pragma once

#include "ScreenPins.h"

namespace Pokitto
{
	#if defined(POKITTO_BOARD_ID)
		// If board revision 1 is in use
		#if (POKITTO_BOARD_ID == 1)

			// Bring Board1 pins into scope
			using namespace Board1;

		// Else if board revision 2 is in use
		#elif (POKITTO_BOARD_ID == 2)

			// Bring Board2 pins into scope
			using namespace Board2;

		#endif
	#endif
}