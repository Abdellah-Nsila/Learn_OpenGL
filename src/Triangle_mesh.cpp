#include "Triangle_mesh.hpp"
#include <glad/glad.h>

TriangleMesh::TriangleMesh()
{
	// std::vector<float> data = {
	//     -1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
	//      1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom right
	//      0.0f,  1.0f, 0.0f, 0.0f, 0.0f, 1.0f  // Top center
	// };
	std::vector<float> position = {
		-1.0f, -1.0f, 0.0f,  // Bottom left
		 1.0f, -1.0f, 0.0f,  // Bottom right
		-1.0f,  1.0f, 0.0f,  // Top left
		 1.0f,  1.0f, 0.0f,  // Top right
	};
	std::vector<int> elementIndices = {
		0, 1, 2,
		2, 3, 1
	};
	std::vector<int> colorsIndices = {
		0, 1, 2, 3
	};
	vertex_count = 6;
	VBOs.resize(2);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(2, VBOs.data());
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
	size_t bufferSize1 = position.size() * sizeof(float);
	glBufferData(GL_ARRAY_BUFFER, bufferSize1, position.data(), 
			GL_STATIC_DRAW);
	//position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12, (void*)0);
	glEnableVertexAttribArray(0);


	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
	size_t bufferSize2 = colorsIndices.size() * sizeof(int);
	glBufferData(GL_ARRAY_BUFFER, bufferSize2, colorsIndices.data(), 
			GL_STATIC_DRAW);
	//colors index
	glVertexAttribIPointer(1, 1, GL_INT, 4, (void*)0);
	glEnableVertexAttribArray(1);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	size_t bufferSize3 = elementIndices.size() * sizeof(int);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, bufferSize3, elementIndices.data(), 
			GL_STATIC_DRAW);
}

void TriangleMesh::draw() {
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, vertex_count, GL_UNSIGNED_INT, 0);
}

TriangleMesh::~TriangleMesh() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(VBOs.size(), VBOs.data());
	glDeleteBuffers(1, &EBO);
}