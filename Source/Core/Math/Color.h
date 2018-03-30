#pragma once
#include "Vector4.h"

namespace MirageMath
{
	struct Color
	{
	public:
		Color();
		Color(float InR, float InG, float InB, float InA);
		Color(float InR, float InG, float InB);
		Color(const Color& InValue);
		Color(const Vector4& InValue);

		void operator = (const Color& InValue);
		bool operator == (const Color& InValue) const;

		float r = 0, g = 0, b = 0, a = 1;
	};
}