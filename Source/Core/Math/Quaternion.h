#pragma once
#include "Vector3.h"

namespace MirageMath
{
	struct Quaternion
	{
	public:
		Quaternion();
		Quaternion(float InX, float InY, float InZ, float InW);
		Quaternion(const Quaternion& InValue);
		Quaternion(const Vector3f& InAxis, const float InDegree);

		Quaternion operator * (const Quaternion& InValue) const;

		float x, y, z, w;
	};
}