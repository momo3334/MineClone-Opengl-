#include "ChunkMeshBuilder.h"


ChunkMeshBuilder::ChunkMeshBuilder(std::vector<glm::vec4> world, Shader & shader, Texture &texture)
	:m_Shader(shader), m_Texture(texture)
{



	for (int i = 0; i < world.size(); i++)
	{
		m_Blocks.push_back(world.at(i));
	}


	//TODO: Generate an optimized mesh for one chunk with the block vector data...



}
	

ChunkMeshBuilder::~ChunkMeshBuilder()
{
}

Mesh * ChunkMeshBuilder::BuildChunk()
{
	enum faces
	{
		Front = 0, Back = 1, Left = 2, Right = 3, Up = 4, Down = 5,
	};


//	for (int i = 0; i < m_Blocks.size(); i++)
//{
//	if (m_Blocks.at(i).x + 1 > 4)
//	{
//		addFace(Front);
//	}
//}

	addFace(Front,1,1,1);
	addFace(Front,3,1,1);
	addFace(Front,5,1,1);


	Mesh* chunkMesh = new Mesh(m_Shader, m_Texture, m_Vertices, m_TexCoords, m_Normals, m_Indices);
	return chunkMesh;
}



void ChunkMeshBuilder::addFace(int face, int posX, int posY, int posZ)
{

	switch (face)
	{
	case 0:
		glm::vec3 translation(posX,posY,posZ);
		//Adding a front face to the mesh

			m_Vertices.push_back(m_Cube.positions.at(3) + translation);
			m_Vertices.push_back(m_Cube.positions.at(4) + translation);
			m_Vertices.push_back(m_Cube.positions.at(5) + translation);
			m_Vertices.push_back(m_Cube.positions.at(16) + translation);


			m_TexCoords.push_back(m_Cube.texCoords.at(3));
			m_TexCoords.push_back(m_Cube.texCoords.at(4));
			m_TexCoords.push_back(m_Cube.texCoords.at(5));
			m_TexCoords.push_back(m_Cube.texCoords.at(16));



			m_Normals.push_back(m_Cube.normals.at(3));
			m_Normals.push_back(m_Cube.normals.at(4));
			m_Normals.push_back(m_Cube.normals.at(5));
			m_Normals.push_back(m_Cube.normals.at(16));
		
			if (posX == 1)
			{
				m_Indices.push_back(0);
				m_Indices.push_back(1);
				m_Indices.push_back(2);
				m_Indices.push_back(3);
				m_Indices.push_back(1);
				m_Indices.push_back(0);
			}
			else if (posX == 3)
			{
				m_Indices.push_back(0 + 4);
				m_Indices.push_back(1 + 4);
				m_Indices.push_back(2 + 4);
				m_Indices.push_back(3 + 4);
				m_Indices.push_back(1 + 4);
				m_Indices.push_back(0 + 4);
			}else
			{
				m_Indices.push_back(0 + 8);
				m_Indices.push_back(1 + 8);
				m_Indices.push_back(2 + 8);
				m_Indices.push_back(3 + 8);
				m_Indices.push_back(1 + 8);
				m_Indices.push_back(0 + 8);
			}		
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
