#pragma once

namespace MirageMath
{
	struct Rotater
	{
	public:
		Rotater();
		Rotater(float, float, float);

		float pitch, yaw, roll;
	};
}