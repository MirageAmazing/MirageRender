#pragma once
#include <list>
#include "IResElement.h"
#include "../Format/VertexFormat.h"

using namespace std;

namespace MirageResource
{
	class ResMesh:IResElement
	{
		friend class ResouceSystem;

	private:
		ResMesh()
		{
			mElementType = eResElementType::Mesh;
		}
		~ResMesh() {}

	public:
		void SetVertexs(list<VertexFormat> vertexs)
		{
			mVertexList = vertexs;
		}
		void AddVertex(VertexFormat vertex)
		{
			mVertexList.push_back(vertex);
		}
		list<VertexFormat> GetVertexs(){return mVertexList;}
		void Clear()
		{
			mVertexList.clear();
		}

	private:

		list<VertexFormat> mVertexList;
		list<uint32> mIndices;
	};
}