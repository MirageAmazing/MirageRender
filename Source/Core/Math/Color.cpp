#include "Color.h"

namespace MirageMath
{
	template<class T>
	Color::Color(T InR, T InG, T InB, T InA)
	{
		r = InR;
		g = InG;
		b = InB;
		a = InA;
	}

	template<class T>
	Color::Color(T InR, T InG, T InB)
	{
		r = InR;
		g = InG;
		b = InB;
		a = 1;
	}

	template<class T>
	Color::Color(const Vector4<T>& InValue)
	{
		r = InValue.x;
		g = InValue.y;
		b = InValue.z;
		a = InValue.w;
	}

	template<class T>
	Color::Color(const Color& InValue)
	{
		r = InValue.r;
		g = InValue.g;
		b = InValue.b;
		a = InValue.a;
	}

	template<class T>
	void Color ::operator  = (const Color& InValue)
	{
		r = InValue.r;
		g = InValue.g;
		b = InValue.b;
		a = InValue.a;
	}

	template<class T>
	bool Color ::operator  == (const Color& InValue) const
	{
		return (r == InValue.r) && (g == InValue.g) && (b == InValue.b) && (a == InValue.a);
	}
}