#pragma once

#include "types.hpp"

namespace c2ba
{

inline bool reduceLogicalOr(const bool3& v) {
    return v.x || v.y || v.z;
}

inline bool reduceLogicalOr(const bool4& v) {
    return v.x || v.y || v.z || v.w;
}

}