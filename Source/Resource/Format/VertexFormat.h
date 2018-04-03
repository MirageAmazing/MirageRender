#pragma once
#include "Core\Math\Vector3.h"
#include "Core\Math\Vector2.h"
#include "Core\Math\Color.h"

using namespace MirageMath;

namespace MirageResource
{
	struct VertexFormat
	{
		Vector3f position;
		Vector2f uv;
		Color color;
	};
}