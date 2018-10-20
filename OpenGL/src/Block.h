#pragma once
#include "glm/glm.hpp"
#include "Mesh.h"
#include <string>

class Block :public Mesh {
public:
	
	enum BlockTypes{
		Grass = 0, Dirt = 1, Air = 2
	};
protected:
private:
	unsigned int m_position;
};