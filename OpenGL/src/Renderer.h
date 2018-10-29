#pragma once


#include<GL/glew.h>

#include "IndexBuffer.h"
#include "Shader.h"
#include "Mesh.h"
#include "Transform.h"
#include "World.h"



#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();

bool GLLogCall(const char* function, const char* file, int line);


class Renderer {
public:
	void Init();
	void Clear() const;
	void pushTranformationMatrix(glm::mat4 camera);
	void Draw(glm::mat4 camera);
private:
	Shader m_Shader;
	Texture m_Texture;
	Transform m_Transform;

	std::vector<Mesh*> toRender;
	std::vector<glm::vec3> positions;
};