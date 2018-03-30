#pragma once
#include "../Core.h"

namespace MirageMath
{
	template<class T> struct Vector2
	{
	public:
		Vector2() 
		{
			x = 0;
			y = 0;
		}
		Vector2(T InX, T InY)
		{
			x = InX;
			y = InY;
		}

		void operator = (const Vector2& InV)
		{
			x = InV.x;
			y = InV.y;
		}

		Vector2 operator + (const Vector2&InV)
		{
			return Vector2(x + InV.x, y + InV.y);
		}
		Vector2 operator - (const Vector2& InV)
		{
			return Vector2(x - InV.x, y - InV.y);
		}
		Vector2 operator * (const Vector2& InV)
		{
			return Vector2(x * InV.x, y * InV.y);
		}
		Vector2 operator * (const T In) const
		{
			return Vector2(x * In, y * In);
		}
		Vector2 operator / (const Vector2& InV)
		{
			return Vector2(x / InV.x, y / InV.y);
		}
		T operator | (const Vector2& In) const
		{
			return x*In.x + y*In.y;
		}
		bool operator == (const Vector2& InValue) const
		{
			return (x == InValue.x) && (y == InValue.y);
		}
		void operator += (const Vector2& InV)
		{
			x += InV.x;
			y += InV.y;
		}
		void operator -= (const Vector2& InV)
		{
			x -= InV.x;
			y -= InV.y;
		}

		bool Normalize()
		{
			auto length = Length();
			if (length == 0)
				return false;
			x /= length;
			y /= length;
			return true;
		}
		T Length()
		{
			return std::sqrt(x*x + y*y);
		}

		static T Dot(const Vector2<T>& InA, const Vector2<T>& InB)
		{
			return InA | InB;
		}

		T x, y;
	};


	template<class T>
	MEINLINE Vector2<T> operator * (const T InValue, const Vector2<T>& InVec)
	{
		return InVec*InValue;
	}

	template<class T>
	MEINLINE Vector2<T> operator / (const T InValue, const Vector2<T>& InVec)
	{
		return Vector2<T>(
			InVec.x == 0 ? 0 : (InValue / InVec.x),
			InVec.y == 0 ? 0 : (InValue / InVec.y)
		);
	}

	typedef Vector2<f32> Vector2f;
	typedef Vector2<f64> Vector2F;
}
