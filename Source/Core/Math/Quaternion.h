#pragma once
#include "Vector3.h"
#include "Rotater.h"
#include "Matrix.h"
#include "MEMath.h"
using namespace MirageMath;

namespace MirageMath
{
	template<class T>
	struct Quaternion
	{
	public:
		Quaternion();
		Quaternion(T InX, T InY, T InZ, T InW);
		Quaternion(const Quaternion& InValue);
		Quaternion(const Vector3<T>& InAxis, const T InDegree);
		Quaternion(T InPitch, T InYaw, T InRoll)
		{
			SetEular(InPitch, InYaw, InRoll);
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
		Quaternion operator * (const T scale) const
		{
			return Quaternion(x*scale, y*scale, z*scale, w*scale);
		}
		Quaternion operator *= (const T scale)
		{
			x *= scale;
			y *= scale;
			z *= scale;
			w *= scale;
			return *this;
		}
		Quaternion operator / (const T scale)const
		{
			T recip = 1.0f / scale;
			return Quaternion(recip*x, recip*y, recip*z, recip*w);
		}
		Quaternion operator /= (const T scale)
		{
			T recip = 1.0f / scale;
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

		Rotater<T> GetRotater() const
		{
			T pitch, yaw, roll;
			const double Epsilon = 0.0009765625f;
			const double Threshold = 0.5f - Epsilon;
			double test = x*y + w*z;

			if (test < -Threshold || test > Threshold) // ÆæÒì×ËÌ¬,¸©Ñö½ÇÎª¡À90¡ã
			{
				double sign = copysign(1.0, test);

				yaw = 2 * sign * atan2(x, w);
				pitch = sign * (ME_PI / 2.0);
				roll = 0;
			}
			else
			{
				double sx{ x*x }, sy{ y*y }, sz{ z*z };

				roll = atan2(2 * (y*w - z*x), 1 - 2 * (sy + sz));
				pitch = asin(2 * test);
				yaw = atan2(2 * (x*w - y*z), 1 - 2 * (sx + sz));
			}

			return Rotater<T>(pitch, yaw, roll);
		}
		Vector3<T> Eular() const
		{
			return GetRotater().Eular();
		}
		Matrix4x4<T> GetMatrix() const
		{
			Matrix4x4f mat;
			
			T sx{ 2 * x*x }, sy{ 2 * y*y }, sz{ 2 * z*z };
			T sxy{ 2 * x*y }, szw{ 2 * z*w }, sxz{ 2 * x*z }, syw{ 2 * y*w }, syz{ 2 * y*z }, sxw{ 2 * x*w };

			mat[0][0] = 1 - sy - sz;
			mat[0][1] = sxy - szw;
			mat[0][2] = sxz + syw;
			mat[0][3] = 0;
			mat[1][0] = sxy + szw;
			mat[1][1] = 1 - sx - sz;
			mat[1][2] = syz - sxw;
			mat[1][3] = 0;
			mat[2][0] = sxz - syw;
			mat[2][1] = syz + sxw;
			mat[2][2] = 1 - sx - sy;
			mat[2][3] = 0;
			mat[3][0] = 0;
			mat[3][1] = 0;
			mat[3][2] = 0;
			mat[3][3] = 1;

			return mat;
		}

		void SetEular(T InPitch, T InYaw, T InRoll){
			T cy = cosf(InYaw*0.5);
			T sy = sinf(InYaw*0.5);
			T cr = cosf(InRoll*0.5);
			T sr = sinf(InRoll*0.5);
			T cp = cos(InPitch*0.5);
			T sp = sin(InPitch*0.5);

			x = cp * cy * sr + sp * sy * cr;
			y = sp * cy * cr + cp * sy * sr;
			z = cp * sy * cr - sp * cy * sr;
			w = cp * cy * cr - sp * sy * sr;

			Normalize();
		}

		void Normalize()
		{
			T tt = x*x + y*y + z*z + w*w;
			T t = tt != 0 ? sqrtf(tt) : 1;
			t = 1.0 / t;
			x *= t;
			y *= t;
			z *= t;
			w *= t;
		}

	public:
		T x, y, z, w;
	};

	using Quaternionf = Quaternion<f32>;
	using QuaternionF = Quaternion<f64>;
}