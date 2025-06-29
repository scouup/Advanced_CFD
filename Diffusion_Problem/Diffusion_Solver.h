#ifndef DIFFUSION_SOLVER_H
#define DIFFUSION_SOLVER_H

#include <string>

// Parameter struct
struct Parameters {
    int N = 20;
    int Ntime = 64;
    double dt = 0.032;
    double u0 = 1.0;
    double aL = 1.0;
    double anu = 0.1;
};

// Function declarations
void solve_diffusion(const Parameters& param);

#endif

