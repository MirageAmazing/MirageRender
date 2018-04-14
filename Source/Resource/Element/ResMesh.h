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

		void SetVertexs(list<Vertex> vertexs)
		{
			mVertexList = vertexs;
		}
		void AddVertex(Vertex vertex)
		{
			mVertexList.push_back(vertex);
		}

	private:

		list<Vertex> mVertexList;
	};
}