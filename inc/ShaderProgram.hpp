#pragma once

# include <string>
# include <glad.h>
# include <fstream>
# include "../glm/gtx/matrix_transform_2d.hpp"
# include <map>
# include <iostream>

class ShaderProgram {
public:
    ShaderProgram();
    ShaderProgram(std::string vertexShader, std::string fragmentShader);
    ~ShaderProgram();

    void    attachShader(const char *fileName, unsigned int shaderType);
    void    link();
    void    use();
    void    setMat3(const std::string &name, const glm::mat3 *value);
    void    setMat4(const std::string &name, const glm::mat4 *value);
    void    setVec3(const std::string &name, const glm::vec3 &value);
    void    setVec4(const std::string &name, const glm::vec4 &value);
    void    setFloat(const std::string &name, const float &value);
    void    setVec2(const std::string &name, const glm::vec2 &value);
    void    addUniform(const std::string &name);
private:
    std::string getShaderFromFile(const char *fileName);
    std::map<std::string, unsigned int> m_UniformVars;
    unsigned int    programId;
};