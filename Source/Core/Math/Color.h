#pragma once
#include "Vector4.h"

namespace MirageMath
{
	template<class T> 
	struct Color
	{
	public:
		Color() = default;
		Color(T InR, T InG, T InB, T InA);
		Color(T InR, T InG, T InB);
		Color(const Color& InValue);
		Color(const Vector4<T>& InValue);

		void operator = (const Color& InValue);
		bool operator == (const Color& InValue) const;

		T r = 0, g = 0, b = 0, a = 1;
	};
}