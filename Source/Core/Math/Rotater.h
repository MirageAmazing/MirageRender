#pragma once
#include "Vector3.h"

namespace MirageMath
{
	struct Rotater
	{
	public:
		Rotater();
		Rotater(float InPitch, float InYaw, float InRoll);

		MEINLINE Rotater operator+(const Rotater& In) const
		{
			return Rotater(pitch + In.pitch, yaw + In.yaw, roll + In.roll);
		}
		MEINLINE Rotater operator-(const Rotater& In) const
		{
			return Rotater(pitch - In.pitch, yaw - In.yaw, roll - In.roll);
		}
		MEINLINE Rotater operator*(const f32 scale) const
		{
			return Rotater(pitch*scale, yaw*scale, roll*scale);
		}
		MEINLINE void operator+=(const Rotater& In)
		{
			pitch += In.pitch;
			yaw += In.yaw;
			roll += In.roll;
		}
		MEINLINE void operator-=(const Rotater& In)
		{
			pitch -= In.pitch;
			yaw -= In.yaw;
			roll -= In.roll;
		}
		MEINLINE Rotater operator*=(const f32 scale)
		{
			pitch *= scale;
			yaw *= scale;
			roll *= scale;

			return *this;
		}
		MEINLINE Rotater operator -() const
		{
			return Rotater(-pitch, -yaw, -roll);
		}
		bool operator == (const Rotater& In) const
		{
			return (pitch == In.pitch) && (yaw == In.yaw) && (roll == In.roll);
		}
		bool operator != (const Rotater& In) const
		{
			return (pitch != In.pitch) && (yaw != In.yaw) && (roll != In.roll);
		}

		MEINLINE Rotater Add(const f32 deltaPitch, const f32 deltaYaw, const f32 deltaRoll)
		{
			pitch += deltaPitch;
			yaw += deltaYaw;
			roll += deltaRoll;
			return *this;
		}
		MEINLINE Vector3f Eular() const
		{
			return Vector3f(roll, pitch, yaw);
		}

	public:
		static Rotater MakeFromEular(const Vector3f& eular) 
		{
			return Rotater(eular.y, eular.z, eular.x);
		}

	public:
		static const Rotater Zero;

	public:
		/*Rotation around the right axis(Y axis), looking up and down.*/
		f32 pitch = 0;
		/*Rotation around the up axis(Z axis), Running in circles.*/
		f32 yaw = 0;
		/*Rotation around the forward axis(X axis), Tilting your head.*/
		f32 roll = 0;
	};
}