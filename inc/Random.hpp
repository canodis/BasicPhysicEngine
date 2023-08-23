#pragma once

#include <unistd.h>
#include <sys/time.h>
#include <ctime>
#include "defines.hpp"
#include <cstdlib>
#include "../glm/glm.hpp"

class Random
{
public:
    [[nodiscard]]
    static float getRandomFloat(float min, float max)
    {
        struct timeval  m_Time;
        gettimeofday(&m_Time, NULL);
        srand(m_Time.tv_usec + m_Time.tv_sec);
        std::cout << min + static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX/(max-min))) << std::endl;
        return min + static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX/(max-min)));
    }
    [[nodiscard]]
    static glm::vec3 getRandomVec3(float min, float max)
    {
        glm::vec3 vec;
        vec.x = getRandomFloat(min, max);
        vec.y = getRandomFloat(min, max);
        vec.z = getRandomFloat(min, max);
        return vec;        
    }
    [[nodiscard]]
    static glm::vec2 getRandomVec2(float min, float max)
    {
        glm::vec2 vec;
        vec.x = getRandomFloat(min, max);
        vec.y = getRandomFloat(min, max);
        return vec;        
    }

    [[nodiscard]]
    static int getRainbow(float t)
    {
        const float r = sin(t);
        const float g = sin(t + 0.33f * 2.0f * PI);
        const float b = sin(t + 0.66f * 2.0f * PI);
        int _r = static_cast<int>(255.0f * r);
        int _g = static_cast<int>(255.0f * g);
        int _b = static_cast<int>(255.0f * b);
        int combinedColor = (_r << 16) | (_g << 8) | _b;
        return combinedColor;
    }
private:
};