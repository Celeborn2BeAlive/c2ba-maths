#pragma once

#include "glm.hpp"
#include "types.hpp"

namespace c2ba {

using glm::distance;
using glm::length;
using glm::dot;
using glm::cross;
using glm::normalize;

using glm::translate;
using glm::rotate;
using glm::scale;
using glm::perspective;
using glm::ortho;
using glm::lookAt;
using glm::inverse;
using glm::transpose;
using glm::determinant;

template<typename T, typename U>
inline auto sqr_distance(const T& lhs, const U& rhs) {
    auto v = rhs - lhs;
    return dot(v, v);
}

template<typename T>
inline auto sqr_length(const T& v) {
    return dot(v, v);
}

template<typename T, typename U>
inline auto abs_dot(const T& lhs, const U& rhs) {
    return abs(dot(lhs, rhs));
}

inline void faceForward(const float3& wi, float3& N) {
    if (dot(wi, N) < 0.f) {
        N = -N;
    }
}

inline float3 getOrthogonalUnitVector(const float3& v) {
    if (abs(v.y) > abs(v.x)) {
        float rcpLength = 1.f / length(float2(v.x, v.y));
        return rcpLength * float3(v.y, -v.x, 0.f);
    }
    float rcpLength = 1.f / length(float2(v.x, v.z));
    return rcpLength * float3(v.z, 0.f, -v.x);
}

inline float3x3 frameY(const float3& yAxis) {
    float3x3 matrix;

    matrix[1] = float3(yAxis);
    if (abs(yAxis.y) > abs(yAxis.x)) {
        float rcpLength = 1.f / length(float2(yAxis.x, yAxis.y));
        matrix[0] = rcpLength * float3(yAxis.y, -yAxis.x, 0.f);
    }
    else {
        float rcpLength = 1.f / length(float2(yAxis.x, yAxis.z));
        matrix[0] = rcpLength * float3(yAxis.z, 0.f, -yAxis.x);
    }
    matrix[2] = cross(matrix[0], yAxis);
    return matrix;
}

// zAxis should be normalized
inline float3x3 frameZ(const float3& zAxis) {
    float3x3 matrix;

    matrix[2] = float3(zAxis);
    if (abs(zAxis.y) > abs(zAxis.x)) {
        float rcpLength = 1.f / length(float2(zAxis.x, zAxis.y));
        matrix[0] = rcpLength * float3(zAxis.y, -zAxis.x, 0.f);
    }
    else {
        float rcpLength = 1.f / length(float2(zAxis.x, zAxis.z));
        matrix[0] = rcpLength * float3(zAxis.z, 0.f, -zAxis.x);
    }
    matrix[1] = cross(zAxis, matrix[0]);
    return matrix;
}

inline float4x4 frameY(const float3& origin, const float3& yAxis) {
    float4x4 matrix;
    matrix[3] = float4(origin, 1);

    matrix[1] = float4(yAxis, 0);
    if (abs(yAxis.y) > abs(yAxis.x)) {
        float rcpLength = 1.f / length(float2(yAxis.x, yAxis.y));
        matrix[0] = rcpLength * float4(yAxis.y, -yAxis.x, 0.f, 0.f);
    }
    else {
        float rcpLength = 1.f / length(float2(yAxis.x, yAxis.z));
        matrix[0] = rcpLength * float4(yAxis.z, 0.f, -yAxis.x, 0.f);
    }
    matrix[2] = float4(cross(float3(matrix[0]), yAxis), 0);
    return matrix;
}

inline float4x4 getViewMatrix(const float3& origin) {
    return glm::translate(glm::mat4(1.f), -origin);
}

// Return a view matrix located at origin and looking toward up direction
inline float4x4 getViewMatrix(const float3& origin, const float3& up) {
    auto frame = frameZ(-up);
    float4x4 m(frame);
    m[3] = float4(origin, 1);
    return inverse(m);
}

}