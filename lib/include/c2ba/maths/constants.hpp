#pragma once

#include "types.hpp"

namespace c2ba {

using glm::one;
using glm::zero;
using glm::pi;
using glm::one_over_pi;
using glm::two_over_pi;

template <typename real>
inline real two_pi() {
    return real(2.0 * pi<real>());
}

template <typename real>
inline real four_pi() {
    return real(4.0 * pi<real>());
}

template <typename real>
inline real one_over_two_pi() {
    return real(0.5 * one_over_pi<real>());
}

template <typename genType>
inline real one_over_four_pi() {
    return real(0.25 * one_over_pi<real>());
}

}
