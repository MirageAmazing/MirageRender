#include "Color.h"

namespace MirageMath
{
	Color::Color()
	{
		r = 0;
		g = 0;
		b = 0;
		a = 1;
	}

	Color::Color(float InR, float InG, float InB, float InA)
	{
		r = InR;
		g = InG;
		b = InB;
		a = InA;
	}

	Color::Color(float InR, float InG, float InB)
	{
		r = InR;
		g = InG;
		b = InB;
		a = 1;
	}

	Color::Color(const Vector4& InValue)
	{
		r = InValue.x;
		g = InValue.y;
		b = InValue.z;
		a = InValue.w;
	}

	Color::Color(const Color& InValue)
	{
		r = InValue.r;
		g = InValue.g;
		b = InValue.b;
		a = InValue.a;
	}

	void Color ::operator  = (const Color& InValue)
	{
		r = InValue.r;
		g = InValue.g;
		b = InValue.b;
		a = InValue.a;
	}

	bool Color ::operator  == (const Color& InValue) const
	{
		return (r == InValue.r) && (g == InValue.g) && (b == InValue.b) && (a == InValue.a);
	}
}