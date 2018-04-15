#pragma once
#include "Vector3.h"
#include "Rotater.h"

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
		Quaternion operator *= (const Quaternion& InValue)
		{
			auto result = *this * InValue;
			x = result.x;
			y = result.y;
			z = result.z;
			w = result.w;
			return *this;
		}
		Quaternion operator * (const f32 scale) const
		{
			return Quaternion(x*scale, y*scale, z*scale, w*scale);
		}
		Quaternion operator *= (const f32 scale)
		{
			x *= scale;
			y *= scale;
			z *= scale;
			w *= scale;
			return *this;
		}
		Quaternion operator / (const f32 scale)const
		{
			f32 recip = 1.0f / scale;
			return Quaternion(recip*x, recip*y, recip*z, recip*w);
		}
		Quaternion operator /= (const f32 scale)
		{
			f32 recip = 1.0f / scale;
			x *= recip;
			y *= recip;
			z *= recip;
			w *= recip;
			return *this;
		}
		bool operator == (const Quaternion& In) const
		{
			return x == In.x && y == In.y && z == In.z && w == In.w;
		}
		bool operator != (const Quaternion& In) const
		{
			return x != In.x && y != In.y && z != In.z && w != In.w;
		}

		Rotater Rotator() const
		{

		}
		Vector3f Eular() const
		{
			return Rotater().Eular();
		}

	public:
		float x, y, z, w;
	};
}