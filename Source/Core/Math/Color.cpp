#include "Color.h"

namespace MirageMath
{
	Color::Color(f32 InR, f32 InG, f32 InB, f32 InA)
	{
		r = InR;
		g = InG;
		b = InB;
		a = InA;
	}

	Color::Color(f32 InR, f32 InG, f32 InB)
	{
		r = InR;
		g = InG;
		b = InB;
		a = 1;
	}

	Color::Color(const Vector4f& InValue)
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