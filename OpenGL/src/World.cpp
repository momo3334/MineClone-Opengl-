#include "World.h"

World::World(int width, int length, int height)
	:m_Width(width), m_Height(height), m_Lenght(length)
{
}

World::~World()
{
}

void World::CreateWorld()
{
	m_Blocks.reserve(sizeof(3 * (m_Width * m_Height * m_Lenght + 1)));
	for (int x = 0; x < m_Width; x++)
	{
		for (int y = 0; y < m_Lenght; y++)
		{
			for (int z = 0; z < m_Height; z++)
			{
				m_Blocks.push_back(glm::vec4(x, y, z, 0));
			}
		}
	}
}

void World::GenerateChunk()
{
	ChunkMeshBuilder chunkMesh(m_Blocks);
}






