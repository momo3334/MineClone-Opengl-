#pragma once
#include <string>
#include<GL/glew.h>
#include "GLCall.h"
#include "stb_image/stb_image.h"


class Texture{
	unsigned int m_RendererID;
	std::string m_FilePath;
	unsigned char* m_LocalBuffer;
	int m_Width, m_Height, m_BPP;
public:
	Texture();
	~Texture();

	void CreateTexture(const std::string& path);
	void Bind(unsigned int slot = 0) const;
	void Unbind();


	inline int GetWith() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }
};