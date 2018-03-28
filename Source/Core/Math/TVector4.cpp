#include "TVector4.h"

TVector4::TVector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

TVector4::TVector4(float InX, float InY, float InZ)
{
	x = InX;
	y = InY;
	z = InZ;
	w = 1;
}

TVector4::TVector4(float InX, float InY, float InZ, float InW)
{
	x = InX;
	y = InY;
	z = InZ;
	w = InW;
}

void TVector4::operator = (TVector4& InV)
{
	x = InV.x;
	y = InV.y;
	z = InV.z;
	w = InV.w;
}

TVector4 TVector4::operator + (TVector4& InV) const
{
	return TVector4(x + InV.x, y + InV.y, z + InV.z, w + InV.w);
}

TVector4 TVector4::operator - (TVector4& InV) const
{
	return TVector4(x - InV.x, y - InV.y, z - InV.z, w - InV.w);
}

TVector4 TVector4::operator * (TVector4& InV) const
{
	return TVector4(x * InV.x, y * InV.y, z * InV.z, w*InV.w);
}

TVector4 TVector4::operator * (float In) const
{
	return TVector4(x * In, y * In, z * In, w*In);
}

TVector4 operator * (const float InValue, const TVector4& InVec)
{
	return InVec*InValue;
}

TVector4 TVector4::operator / (TVector4& InV) const
{
	return TVector4(x / InV.x, y / InV.y, z / InV.z, w / InV.w);
}

TVector4 operator / (const float InValue, const TVector4& InVec)
{
	return TVector4(
		InVec.x == 0 ? 0 : (InValue / InVec.x),
		InVec.y == 0 ? 0 : (InValue / InVec.y),
		InVec.z == 0 ? 0 : (InValue / InVec.z),
		InVec.w == 0 ? 0 : (InValue / InVec.w)
	);
}

bool TVector4::operator == (TVector4& InValue) const
{
	return (x == InValue.x) && (y == InValue.y) && (z == InValue.z) && (w == InValue.w);
}

void TVector4::operator += (TVector4& InV)
{
	x += InV.x;
	y += InV.y;
	z += InV.z;
	w += InV.w;
}

void TVector4::operator -= (TVector4& InV)
{
	x -= InV.x;
	y -= InV.y;
	z -= InV.z;
	w -= InV.w;
}