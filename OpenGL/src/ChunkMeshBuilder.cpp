#include "ChunkMeshBuilder.h"


ChunkMeshBuilder::ChunkMeshBuilder(std::vector<glm::vec4> world)
{
	enum faces
	{
		Front = 0, Back = 1, Left = 2, Right = 3, Up = 4, Down = 5,
	};


	for (int i = 0; i < 125; i++)
	{
		m_Blocks.push_back(world.at(i));
	}


	//TODO: Generate an optimized mesh for one chunk with the block vector data...

	for (int i = 0; i < m_Blocks.size(); i++)
	{
		if (m_Blocks.at(i).x + 1 > 4)
		{
			addFace(Front);
		}
	}
}
	

ChunkMeshBuilder::~ChunkMeshBuilder()
{
}

void ChunkMeshBuilder::addFace(int face)
{

	switch (face)
	{
	case 0:
		
		//Adding a front face to the mesh
		m_Vertices.push_back(m_Cube.positions.at(1));
		m_Vertices.push_back(m_Cube.positions.at(2));
		m_Vertices.push_back(m_Cube.positions.at(3));

		m_TexCoords.push_back(m_Cube.texCoords.at(1));
		m_TexCoords.push_back(m_Cube.texCoords.at(2));
		m_TexCoords.push_back(m_Cube.texCoords.at(3));

		m_Normals.push_back(m_Cube.normals.at(1));
		m_Normals.push_back(m_Cube.normals.at(2));
		m_Normals.push_back(m_Cube.normals.at(3));

		m_Indices.push_back(1);
		m_Indices.push_back(2);
		m_Indices.push_back(3);
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	}
}
