#pragma once
#include "World.h"

class ChunkMeshBuilder {
public:	
	ChunkMeshBuilder(std::vector<glm::vec4> world, Shader & shader, Texture &texture);
	~ChunkMeshBuilder();

	Mesh* BuildChunk();

	void addFace(int face, int posX, int posY, int posZ);
protected:
private:
	
	std::vector<glm::vec4> m_Blocks;

	std::vector<glm::vec3> m_Vertices;
	std::vector<glm::vec2> m_TexCoords;
	std::vector<glm::vec3> m_Normals;
	std::vector<unsigned int> m_Indices;

	IndexedModel m_Cube = OBJModel("res/Models/Block.obj").ToIndexedModel();

	Shader & m_Shader;
	Texture &m_Texture;
};