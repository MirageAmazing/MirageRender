#pragma once

#include "../MirageEngine.h"

namespace MirageResource
{
	class IResElement
	{
	public:
		IResElement() {}
		virtual ~IResElement() {}

	private:
		MEGUID guid;
	};
}