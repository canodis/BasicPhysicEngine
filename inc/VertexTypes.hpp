#pragma once

# include "../glm/glm.hpp"
# include <vector>

class Object2dTex
{
public:
	glm::vec2 pos;
	glm::vec2 texCoord;
};

class Object2dColor
{
public:
	glm::vec2 pos;
	glm::vec4 rgba;
};

typedef std::vector<unsigned int>   IndexList;
typedef std::vector<glm::vec2>      PositionList;
typedef std::vector<glm::vec2>      TextCoordList;
typedef std::vector<Object2dTex>    Object2dTexList;
typedef std::vector<Object2dColor>  Object2dColorList;