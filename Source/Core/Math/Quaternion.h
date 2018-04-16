#pragma once
#include "Vector3.h"
#include "Rotater.h"
#include "MEMath.h"
using namespace MirageMath;

namespace MirageMath
{
	struct Quaternion
	{
	public:
		Quaternion();
		Quaternion(float InX, float InY, float InZ, float InW);
		Quaternion(const Quaternion& InValue);
		Quaternion(const Vector3f& InAxis, const float InDegree);
		Quaternion(float InPitch, float InYaw, float InRoll)
		{
			float cy = cosf(InYaw*0.5);
			float sy = sinf(InYaw*0.5);
			float cr = cosf(InRoll*0.5);
			float sr = sinf(InRoll*0.5);
			float cp = cos(InPitch*0.5);
			float sp = sin(InPitch*0.5);

			w = cy * cr * cp + sy * sr * sp;
			x = cy * sr * cp - sy * cr * sp;
			y = cy * cr * sp + sy * sr * cp;
			z = sy * cr * cp - cy * sr * sp;
		}

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

		Rotater GetRotater() const
		{
			const double Epsilon = 0.0009765625f;
			const double Threshold = 0.5f - Epsilon;
			double TEST = w*y - x*z;

			float pitch, yaw, roll;

			if (TEST < -Threshold || TEST > Threshold) // ÆæÒì×ËÌ¬,¸©Ñö½ÇÎª¡À90¡ã
			{
				double sign = copysign(1.0, TEST);

				yaw = -2 * sign * (double)atan2(x, w); // yaw

				pitch = sign * (ME_PI / 2.0); // pitch

				roll = 0; // roll
			}
			else
			{
				roll = atan2(2 * (y*z + w*x), w*w - x*x - y*y + z*z);
				pitch = asin(-2 * (x*z - w*y));
				yaw = atan2(2 * (x*y + w*z), w*w + x*x - y*y - z*z);
			}

			return Rotater(pitch, yaw, roll);
		}
		Vector3f Eular() const
		{
			return GetRotater().Eular();
		}

	public:
		float x, y, z, w;
	};
}