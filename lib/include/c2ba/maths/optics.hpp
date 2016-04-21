#pragma once

#include "types.hpp"
#include "constants.hpp"

namespace c2ba 
{

inline float3 reflect(const float3& I, const float3& N)
{
    return glm::reflect(-I, N);
}

inline float3 refract(const float3& I, const float3& N, float eta)
{
    auto dotI = dot(I, N);

    auto sqrDotO = 1 - sqr(eta) * (1 - sqr(dotI));
    if (sqrDotO < 0.f) {
        return zero<float3>();
    }
    auto k = sqrt(sqrDotO);
    return -eta * I + (eta * dotI - sign(dotI) * k) * N;
}

}