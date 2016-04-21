#pragma once

#include "../types.hpp"
#include "../numeric.hpp"

namespace c2ba
{

// Same convention as OpenGL:
enum class CubeFace {
    POS_X = 0,
    NEG_X = 1,
    POS_Y = 2,
    NEG_Y = 3,
    POS_Z = 4,
    NEG_Z = 5,
    FACE_COUNT = 6
};

inline CubeFace getCubeFace(const float3& wi) {
    float3 absWi = abs(wi);

    float maxComponent = max(absWi.x, max(absWi.y, absWi.z));

    if (maxComponent == absWi.x) {
        if (wi.x > 0) {
            return CubeFace::POS_X;
        }
        return CubeFace::NEG_X;
    }

    if (maxComponent == absWi.y) {
        if (wi.y >= 0) {
            return CubeFace::POS_Y;
        }
        return CubeFace::NEG_Y;
    }

    if (maxComponent == absWi.z) {
        if (wi.z > 0) {
            return CubeFace::POS_Z;
        }
    }

    return CubeFace::NEG_Z;
}

}