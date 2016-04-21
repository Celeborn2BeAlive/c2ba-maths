#pragma once

#include "glm.hpp"
#include "constants.hpp"

namespace c2ba {

template<typename T>
inline T rcp(const T& value) {
    return one<T>() / value;
}

template<typename T>
inline T sqr(const T& value) {
    return value * value;
}

using glm::abs;

using glm::radians;
using glm::degrees;

using glm::cos;
using glm::sin;
using glm::tan;
using glm::abs;
using glm::floor;
using glm::sign;
using glm::max;
using glm::min;
using glm::clamp;
using glm::fract;
using glm::pow;
using glm::sqrt;

using glm::isnan;
using glm::isinf;
using glm::isfinite;
using glm::isPowerOfTwo;

inline float reduceMax(const float3& v) {
    return max(v.x, max(v.y, v.z));
}

// Return the index of the maximal component of the vector
inline uint32_t maxComponent(const float3& v) {
    auto m = reduceMax(v);
    if (m == v.x) {
        return 0u;
    }
    if (m == v.y) {
        return 1u;
    }
    return 2u;
}

}