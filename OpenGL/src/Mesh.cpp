#include "Mesh.h"









Mesh::Mesh(Shader & shader,Texture & texture)
	:m_Shader(shader), m_Texture(texture)
{
	va.Bind();
	m_Texture.CreateTexture("res/textures/sprite.png");
	m_Texture.Bind();
	m_Shader.SetUniform1i("u_Texture", 0);



	IndexedModel model = OBJModel(m_ObjFileName).ToIndexedModel();


	//Affecting member data to model data
	m_Postitions = model.positions;
	m_texCoords = model.texCoords;
	m_Indices = model.indices;
	m_Normal = model.normals;
	m_DrawCount = model.indices.size();
	
	//Setting up the position buffer and adding its attribute to the VertexAttribute Array
	VertexBuffer positionBuffer(&m_Postitions[0], model.positions.size() * 3 * sizeof(float));
	VertexBufferLayout positionlayout;
	positionlayout.Push<float>(3);
	va.AddBuffer(0, positionBuffer, positionlayout); //TODO Optimise the vaIndex to be set automatically with each call to the "AddBuffer" function

	//Setting up the texture buffer and adding its attribute to the VertexAttribute Array
	VertexBuffer texCoordsBuffer(&model.texCoords[0], model.positions.size() * 2 * sizeof(float));
	VertexBufferLayout texCoordsLayout;
	texCoordsLayout.Push<float>(2);
	va.AddBuffer(1, texCoordsBuffer, texCoordsLayout); //TODO Optimise the vaIndex to be set automatically with each call to the "AddBuffer" function

	//Setting up the normals buffer and adding its attribute to the VertexAttribute Array
	VertexBuffer normalsBuffer(&model.normals[0], model.normals.size() * 3 * sizeof(float));
	VertexBufferLayout normalsLayout;
	normalsLayout.Push<float>(3);
	va.AddBuffer(2, normalsBuffer, normalsLayout); //TODO Optimise the vaIndex to be set automatically with each call to the "AddBuffer" function


	va.Unbind();
	//Setting up index buffer

	GLCall(glGenBuffers(1, &m_ibID));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibID));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_DrawCount * sizeof(model.indices[0]), &m_Indices[0], GL_STATIC_DRAW));

	
}

Mesh::Mesh(Shader & shader, Texture & texture, std::vector<glm::vec3> postitions, std::vector<glm::vec2> texCoords, std::vector<glm::vec3> normal, std::vector<unsigned int> indices)
	:m_Shader(shader), m_Texture(texture)
{
	va.Bind();
	m_Texture.CreateTexture("res/textures/sprite.png");
	m_Texture.Bind();
	m_Shader.SetUniform1i("u_Texture", 0);



	//Affecting member data to model data
	m_Postitions = postitions;
	m_texCoords = texCoords;
	m_Indices = indices;
	m_Normal = normal;
	m_DrawCount = indices.size();

	//Setting up the position buffer and adding its attribute to the VertexAttribute Array
	VertexBuffer positionBuffer(&postitions[0], postitions.size() * sizeof(postitions[0]));
	VertexBufferLayout positionlayout;
	positionlayout.Push<float>(3);
	va.AddBuffer(0, positionBuffer, positionlayout); //TODO Optimise the vaIndex to be set automatically with each call to the "AddBuffer" function

	//Setting up the texture buffer and adding its attribute to the VertexAttribute Array
	VertexBuffer texCoordsBuffer(&texCoords[0], texCoords.size() * sizeof(texCoords[0]));
	VertexBufferLayout texCoordsLayout;
	texCoordsLayout.Push<float>(2);
	va.AddBuffer(1, texCoordsBuffer, texCoordsLayout); //TODO Optimise the vaIndex to be set automatically with each call to the "AddBuffer" function

	//Setting up the normals buffer and adding its attribute to the VertexAttribute Array
	VertexBuffer normalsBuffer(&normal[0], normal.size() * sizeof(normal[0]));
	VertexBufferLayout normalsLayout;
	normalsLayout.Push<float>(3);
	va.AddBuffer(2, normalsBuffer, normalsLayout); //TODO Optimise the vaIndex to be set automatically with each call to the "AddBuffer" function


	va.Unbind();
	//Setting up index buffer

	GLCall(glGenBuffers(1, &m_ibID));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibID));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_DrawCount * sizeof(indices[0]), &indices[0], GL_STATIC_DRAW));

}

Mesh::~Mesh()
{

}


void Mesh::Bind()
{

}


void Mesh::Draw(Shader & shader)
{
	//m_Shader.Bind();
	shader.Bind();
 	va.Bind();
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibID));
	GLCall(glDrawElements(GL_TRIANGLES, m_DrawCount, GL_UNSIGNED_INT, nullptr));
}

GLuint Mesh::getVAOId()
{
	return va.getId();
}

