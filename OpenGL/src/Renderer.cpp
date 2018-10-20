#include "Renderer.h"
#include <iostream>

void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL Error] (" << error << ")" << function << " " <<
			file << "|line: " << line << std::endl;
		return false;
	}
	return true;
}

void Renderer::Init()
{

	m_Shader.makeShader("res/Shaders/Basic.shader");
	m_Shader.Bind();
	m_Shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);
	m_Texture.CreateTexture("res/textures/sprite.png");
	
	toRender.push_back(new Mesh(m_Shader, m_Texture));

	for (unsigned int x = 0; x < 5; x++)
	{
		for (unsigned int  y = 0; y < 5; y++)
		{
			for (unsigned int z = 0; z < 1; z++)
			{
				positions.push_back(glm::vec3(x * 2.0f, z * 2.0f, y * 2.0f));
			}
		}
	}



}

void Renderer::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::pushTranformationMatrix(glm::mat4 camera)
{
	m_Shader.Bind();
	glm::mat4 mvp = camera * m_Transform.GetModel();
	m_Shader.SetUniformMath4f("u_MVP", mvp);
}

void Renderer::Draw(glm::mat4 camera)
{
	for (int i = 0; i < toRender.size(); i++)
	{
		for (unsigned int j = 0; j < positions.size(); j++)
		{
			m_Transform.GetPos() =  positions.at(j);
			pushTranformationMatrix(camera);
			toRender.at(i)->Draw(m_Shader);
		}
	}
}