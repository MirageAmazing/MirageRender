#pragma once
#include "Vector3.h"

namespace MirageMath
{
	struct alignas(16) Matrix
	{
	public:
		Matrix();
		Matrix(Vector3f&, Vector3f&, Vector3f&, Vector3f&);
		Matrix(Vector3f&&, Vector3f&&, Vector3f&&, Vector3f&&);
		Matrix(const Matrix&);

		Matrix operator + (const Matrix&) const;
		Matrix operator - (const Matrix&) const;
		Matrix operator * (const Matrix&) const;
		Matrix operator * (double) const;
		void operator = (const Matrix&);
		double* const operator[](const int);
		Matrix Inverse();

		void SetElement(const int, const int, const double);

		static Matrix IndentityMatrix();
		static Matrix Translate(float x, float y, float z);
		static Matrix Translate(const Vector3f& In);
		static Matrix Scale(float x, float y, float z);
		static Matrix Scale(const Vector3f& In);
		static Matrix Rotate(float degree, const Vector3f& axis);
		static Matrix Perspertive(const float fovy, const float aspect, const float near, const float far);
		static Matrix Ortho(float left, float right, float bottom, float top, float n, float f);
		static Matrix LookAt(const Vector3f& eye, const Vector3f& center, const Vector3f& up);
	private:

		double data[4][4];
	};
}