#pragma once
#include <string>
#include <vector>
#include "glm/glm.hpp"
#include "objLoader/obj_loader.h"
#include "VertexBufferLayout.h"
#include "VertexArray.h"
#include "Texture.h"
#include "Shader.h"

class Mesh {
public:


	Mesh(Shader & shader, Texture & texture);
	Mesh(Shader & shader, Texture & texture, std::vector<glm::vec3> m_Postitions, std::vector<glm::vec2> m_TexCoords, std::vector<glm::vec3> m_Normal, std::vector<unsigned int> indices);
	~Mesh();


	void Bind();

	void Transform(glm::mat4 Camera);


	void Draw(Shader& shader);


	GLuint getVAOId();

private:
	std::vector<glm::vec3> m_Postitions;
	std::vector<glm::vec2> m_texCoords;
	std::vector<glm::vec3> m_Normal;
	std::vector<unsigned int> m_Indices;

	unsigned int m_DrawCount;
	unsigned int m_VerticesCount;
	//float m_quantity;
	
	GLuint m_ibID;
	VertexArray va;

	Shader & m_Shader;
	Texture &m_Texture;


	std::string m_ObjFileName = "res/Models/Block.obj";
	std::string m_ShaderFileName = "res/Shaders/Basic.shader";
	std::string m_TexFileName = "res/textures/sprite.png";
};