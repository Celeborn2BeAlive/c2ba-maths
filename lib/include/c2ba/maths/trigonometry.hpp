#pragma once

namespace c2ba 
{

template<typename T> inline T sin2cos(const T& x) {
    return sqrt(max(T(0.f), T(1.f) - x * x));
}

template<typename T> inline T cos2sin(const T& x) {
    return sin2cos(x);
}

}