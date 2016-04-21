#pragma once

namespace c2ba {

inline float balanceHeuristicWeight(float pf, float fPdf, float gPdf) {
    auto f = pf * fPdf;
    return f / (f + (1 - pf) * gPdf);
}

inline float powerHeuristicWeight(float pf, float fPdf, float gPdf) {
    auto f = pf * fPdf, g = (1 - pf) * gPdf;
    return (f * f) / (f * f + g * g);
}

}
