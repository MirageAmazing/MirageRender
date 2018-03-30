#include "Rotater.h"

namespace MirageMath
{
	Rotater::Rotater()
	{
		pitch = 0;
		yaw = 0;
		roll = 0;
	}

	Rotater::Rotater(float InPitch, float InYaw, float InRoll)
	{
		pitch = InPitch;
		yaw = InYaw;
		roll = InRoll;
	}
}