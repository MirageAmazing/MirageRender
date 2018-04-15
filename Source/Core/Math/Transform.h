#pragma once
#include "Vector3.h"
#include "Quaternion.h"

namespace MirageMath
{
	class  Transform
	{
	public:
		Transform();
		~Transform();

	private:
		Vector3f mLocation;
		Vector3f mScale;
		Quaternion mRotation;
	};

}
