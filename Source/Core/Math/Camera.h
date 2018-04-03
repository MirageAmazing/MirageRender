#pragma once
#include "Core\Math\Vector3.h"
#include "Core\Math\Matrix.h"

namespace MirageMath
{
	class Camera
	{
	public:
		Camera(Vector3f viewLocation, Vector3f viewCenter, Vector3f viewUp)
		{
			mViewMatrix = Matrix4x4f::LookAt(viewLocation, viewCenter, viewUp);
		}


	private:
		Vector3f mViewLocation, mViewDirection, mViewUp;
		f32 mFOV;
		f32 mNear, mFar;

		int mSurfaceWidth, mSurfaceHeight;

		Matrix4x4f mViewMatrix;
	};
}