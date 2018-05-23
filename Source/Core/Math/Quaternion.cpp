#include "Quaternion.h"
#include <cmath>

namespace MirageMath
{
	template<class T>
	Quaternion::Quaternion()
	{

	}

	template<class T>
	Quaternion::Quaternion(T InX, T InY, T InZ, T InW) :
		x(InX), y(InY), z(InZ), w(InW)
	{

	}

	template<class T>
	Quaternion::Quaternion(const Quaternion& InValue) :
		x(InValue.x), y(InValue.y), z(InValue.z), w(InValue.w)
	{

	}

	template<class T>
	Quaternion::Quaternion(const Vector3<T>& InAxis, const T InDegree)
	{
		auto halfDegree = InDegree*0.5;
		auto reciprocal = 1.0 / sqrt(InAxis.x*InAxis.x + InAxis.y*InAxis.y + InAxis.z*InAxis.z);
		x = InAxis.x*sin(halfDegree)*reciprocal;
		y = InAxis.y*sin(halfDegree)*reciprocal;
		z = InAxis.z*sin(halfDegree)*reciprocal;
		w = cos(halfDegree);

		Normalize();
	}

	template<class T>
	Quaternion Quaternion::operator * (const Quaternion& InValue) const
	{
		/*
		// Meth 1: 最直接的四元数乘法
		T tempx = w*InValue.x + x*InValue.w + y*InValue.z - z*InValue.y;
		T tempy = w*InValue.y + y*InValue.w + z*InValue.x - x*InValue.z;
		T tempz = w*InValue.z + z*InValue.w + x*InValue.y - y*InValue.x;
		T tempw = w*InValue.w - x*InValue.x - y*InValue.y - z*InValue.z;
		*/

		/*
			Meth 2: 将四元数看成（v，s）一个向量和一个标量
			Q1(v1, s1) * Q2(v2, s2) = s1*s2-Dot(v1, v2)+ s1*v2 + s2*v1 + Cross(v1, v2)
		*/

		Vector3<T> va(x, y, z);
		Vector3<T> vb(InValue.x, InValue.y, InValue.z);

		auto dotValue = Vector3<T>::Dot(va, vb);
		auto crossValue = Vector3<T>::Cross(va, vb);
		auto vertorA = vb*w;
		auto vertorB = va*InValue.w;
		auto scalarValue = w*InValue.w;

		auto scalar = scalarValue - dotValue;
		auto vector = crossValue + vertorA + vertorB;

		return Quaternion(vector.x, vector.y, vector.z, scalar);
	}
}