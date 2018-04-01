#pragma once
#include "Vector4.h"

namespace MirageMath
{
	struct Color
	{
	public:
		Color();
		Color(f32 InR, f32 InG, f32 InB, f32 InA);
		Color(f32 InR, f32 InG, f32 InB);
		Color(const Color& InValue);
		Color(const Vector4f& InValue);

		void operator = (const Color& InValue);
		bool operator == (const Color& InValue) const;

		f32 r = 0, g = 0, b = 0, a = 1;
	};
}