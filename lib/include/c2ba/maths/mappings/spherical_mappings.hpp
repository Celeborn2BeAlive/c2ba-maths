#pragma once

#include "../numeric.hpp"
#include "../constants.hpp"

#include "image_mappings.hpp"

namespace c2ba {

inline float2 getSphericalAngles(const float2& uv) {
    return uv * float2(two_pi<float>(), pi<float>());
}

// Standard spherical mapping [0,1]x[0,1] -> UnitSphere
inline float3 sphericalMapping(const float2& uv, float& sinTheta) {
    auto phiTheta = getSphericalAngles(uv);
    sinTheta = sin(phiTheta.y);

    return float3(cos(phiTheta.x) * sinTheta,
                 sin(phiTheta.x) * sinTheta,
                 cos(phiTheta.y));
}

inline float3 sphericalMapping(const float2& uv) {
    float sinTheta;
    return sphericalMapping(uv, sinTheta);
}

inline float sphericalMappingJacobian(const float2& uv, float& sinTheta) {
    auto phiTheta = getSphericalAngles(uv);
    sinTheta = sin(phiTheta.y);
    return abs(two_pi<float>() * pi<float>() * sinTheta);
}

inline float sphericalMappingJacobian(const float2& uv) {
    float sinTheta;
    return sphericalMappingJacobian(uv, sinTheta);
}

inline float2 rcpSphericalMapping(const float3& wi, float& sinTheta) {
    sinTheta = sqrt(sqr(wi.x) + sqr(wi.y));
    float2 phiTheta;

    phiTheta.x = atan2(wi.y / sinTheta, wi.x / sinTheta);
    phiTheta.y = atan2(sinTheta, wi.z);

    if(phiTheta.x < 0.f) {
        phiTheta.x += two_pi<float>();
    }

    if(phiTheta.y < 0.f) {
        phiTheta.y += two_pi<float>();
    }

    return phiTheta * float2(one_over_two_pi<float>(), one_over_pi<float>());
}

inline float2 rcpSphericalMapping(const float3& wi) {
    float sinTheta;
    return rcpSphericalMapping(wi, sinTheta);
}

inline float rcpSphericalMappingJacobian(const float3& wi, float& sinTheta) {
    sinTheta = sqrt(sqr(wi.x) + sqr(wi.y));
    return sinTheta == 0.f ? 0.f : abs(1.f / (two_pi<float>() * pi<float>() * sinTheta));
}

inline float rcpSphericalMappingJacobian(const float3& wi) {
    float sinTheta;
    return rcpSphericalMappingJacobian(wi, sinTheta);
}

/**
* @brief cartesianToSpherical
* @param direction a unit length 3D vector
* @return Spherical coordinates (phi, theta) of direction with phi in [0, 2pi[ and theta in [-pi, pi]
*/
inline float2 cartesianToSpherical(const float3& direction) {
    return float2(atan2(direction.x, direction.z), asin(direction.y));
}

/**
* @brief sphericalToCartesian
* @param angles The spherical angles: angles.x is phi and angles.y is theta
* @return Cartesian coordinates
*/
inline float3 sphericalToCartesian(const float2& angles) {
    auto cosTheta = cos(angles.y);
    return float3(sin(angles.x) * cosTheta,
        sin(angles.y),
        cos(angles.x) * cosTheta);
}


}
