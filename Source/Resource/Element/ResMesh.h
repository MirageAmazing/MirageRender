#pragma once
#include <list>
#include "IResElement.h"
#include "../Format/VertexFormat.h"

using namespace std;

namespace MirageResource
{
	class ResMesh:IResElement
	{
	public:
		ResMesh(){}
		~ResMesh() {}

		void SetVertexs(list<VertexFormat> vertexs)
		{
			mVertexList = vertexs;
		}
		void AddVertex(VertexFormat vertex)
		{
			mVertexList.push_back(vertex);
		}
	private:

		list<VertexFormat> mVertexList;
	};
}