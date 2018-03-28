#pragma once

#define T_E				2.71828182845904523536   // e
#define T_LOG2E		1.44269504088896340736   // log2(e)
#define T_LOG10E		0.434294481903251827651  // log10(e)
#define T_LN2			0.693147180559945309417  // ln(2)
#define T_LN10			2.30258509299404568402   // ln(10)
#define T_PI				3.14159265358979323846   // pi
#define T_PI_2			1.57079632679489661923   // pi/2
#define T_PI_4			0.785398163397448309616  // pi/4
#define T_1_PI			0.318309886183790671538  // 1/pi
#define T_2_PI			0.636619772367581343076  // 2/pi
#define T_2_SQRTPI	1.12837916709551257390   // 2/sqrt(pi)
#define T_SQRT2		1.41421356237309504880   // sqrt(2)
#define T_SQRT1_2		0.707106781186547524401  // 1/sqrt(2)

inline float DegreeToRadians(float degree) { return degree*T_PI / 180.0f; }
inline float RadiansToDegree(float radians) { return radians*180.0f / T_PI; }