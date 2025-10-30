#pragma once

#include <vector>

class TriangleMesh
{
	public:
		TriangleMesh();
		void draw();
		~TriangleMesh();

	private:
		std::vector<unsigned int>VBOs;
		unsigned int VAO, EBO, vertex_count;
};
