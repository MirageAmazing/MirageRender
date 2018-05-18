#pragma once
#include "Vector3.h"
#include "Quaternion.h"

namespace MirageMath
{
	class Transform
	{
	public:
		Transform() : translation(0), scale(1), rotation(0,0,0)
		{
		}
		Transform(Transform& in) 
		{
			translation = in.translation;
			scale = in.scale;
			rotation = in.rotation;
		}
		~Transform() {}

		Matrix4x4f GetTransformMatrix() const
		{
			//Matrix4x4f::Translate()
		}

	private:
		Vector3f translation;
		Vector3f scale;
		Quaternion rotation;
	};

}
