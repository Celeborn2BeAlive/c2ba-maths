#pragma once

#include "logic.hpp"

namespace c2ba
{

inline bool isInvalidMeasurementEstimate(const float3& c) {
    return c.r < 0.f || c.g < 0.f || c.b < 0.f ||
        reduceLogicalOr(isnan(c)) || reduceLogicalOr(isinf(c));
}

inline bool isInvalidMeasurementEstimate(const float4& c) {
    return isInvalidMeasurementEstimate(float3(c));
}

inline float luminance(const float3& color) {
    return 0.212671f * color.r + 0.715160f * color.g + 0.072169f * color.b;
}

}