#pragma once

#include "../MirageEngine.h"
#include "../Core/Math/MEMath.h"

namespace MirageResource
{
	class ResMesh;

	/*
	 Type of resource
	*/
	enum class eResElementType
	{
		Mesh,
		Texture,
		Audio,

		Count,
		None
	};

	/*
	 Basic type of resouce element.
	*/
	class IResElement
	{
	public:
		MEINLINE eResElementType GetType(){ return mElementType;}

		IResElement(ResMesh&) {}

	protected:
		IResElement() 
		{
			mGuid = GenerateUID();
		}
		virtual ~IResElement() {}

		eResElementType mElementType{eResElementType::None};
	private:
		MEUID mGuid;
	};
}