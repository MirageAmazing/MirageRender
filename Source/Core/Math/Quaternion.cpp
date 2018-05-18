#include "Quaternion.h"
#include <cmath>

namespace MirageMath
{
	Quaternion::Quaternion()
	{

	}

	Quaternion::Quaternion(float InX, float InY, float InZ, float InW) :
		x(InX), y(InY), z(InZ), w(InW)
	{

	}

	Quaternion::Quaternion(const Quaternion& InValue) :
		x(InValue.x), y(InValue.y), z(InValue.z), w(InValue.w)
	{

	}

	Quaternion::Quaternion(const Vector3f& InAxis, const float InDegree)
	{
		auto halfDegree = InDegree*0.5;
		auto reciprocal = 1.0 / sqrt(InAxis.x*InAxis.x + InAxis.y*InAxis.y + InAxis.z*InAxis.z);
		x = InAxis.x*sin(halfDegree)*reciprocal;
		y = InAxis.y*sin(halfDegree)*reciprocal;
		z = InAxis.z*sin(halfDegree)*reciprocal;
		w = cos(halfDegree);

		Normalize();
	}

	Quaternion Quaternion::operator * (const Quaternion& InValue) const
	{
		/*
		// Meth 1: 最直接的四元数乘法
		float tempx = w*InValue.x + x*InValue.w + y*InValue.z - z*InValue.y;
		float tempy = w*InValue.y + y*InValue.w + z*InValue.x - x*InValue.z;
		float tempz = w*InValue.z + z*InValue.w + x*InValue.y - y*InValue.x;
		float tempw = w*InValue.w - x*InValue.x - y*InValue.y - z*InValue.z;
		*/

		/*
			Meth 2: 将四元数看成（v，s）一个向量和一个标量
			Q1(v1, s1) * Q2(v2, s2) = s1*s2-Dot(v1, v2)+ s1*v2 + s2*v1 + Cross(v1, v2)
		*/

		Vector3f va(x, y, z);
		Vector3f vb(InValue.x, InValue.y, InValue.z);

		auto dotValue = Vector3f::Dot(va, vb);
		auto crossValue = Vector3f::Cross(va, vb);
		auto vertorA = vb*w;
		auto vertorB = va*InValue.w;
		auto scalarValue = w*InValue.w;

		auto scalar = scalarValue - dotValue;
		auto vector = crossValue + vertorA + vertorB;

		return Quaternion(vector.x, vector.y, vector.z, scalar);
	}
}