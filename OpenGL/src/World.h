#pragma once
#include "Mesh.h"
#include "ChunkMeshBuilder.h"


class World {
public:
	World(int width, int length, int height);
	~World();

	void CreateWorld();


	void GenerateChunk();

protected:
private:
	unsigned int m_Width;
	
	unsigned int m_Lenght;
	
	unsigned int m_Height;

	std::vector<glm::vec4> m_Blocks;
};