#include "Diffusion_Solver.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

void solve_diffusion(const Parameters& param) {
    const double pi = 4.0 * atan(1.0);
    int N = param.N;
    int Ntime = param.Ntime;
    double dt = param.dt;
    double u0 = param.u0;
    double aL = param.aL;
    double anu = param.anu;

    vector<double> u(N + 1, 0.0);
    vector<double> uold(N + 1, 0.0);

    double dy = 2.0 * aL / N;
    double CFL = dt * anu / (dy * dy);

    cout << "anu, dt, aL, dy, CFL= " << anu << " " << dt << " " << aL << " " << dy << " " << CFL << endl;

    double t = 0.0;
    double Tend = 3.0 * aL * aL / anu;
    int nsteps = static_cast<int>(Tend / dt);

    cout << "Tend, dt, Ntime, nsteps= " << Tend << " " << dt << " " << Ntime << " " << nsteps << endl;

    ofstream fout("result.dat");
    fout << fixed << setprecision(12);

    for (int it = 1; it <= nsteps; ++it) {
        for (int j = 1; j < N; ++j) {
            u[j] = uold[j] + CFL * (uold[j - 1] - 2.0 * uold[j] + uold[j + 1])
                 + dt * 2.0 * u0 * anu / (aL * aL);
        }

        for (int j = 1; j < N; ++j) {
            uold[j] = u[j];
        }

        t += dt;

        if (it % Ntime == 0) {
            for (int j = 0; j <= N; ++j) {
                double ycc = static_cast<double>(j) * dy - 1.0;
                double theory1 = 1.0 - ycc * ycc;

                for (int k = 0; k <= 100; ++k) {
                    double ss = (0.5 + static_cast<double>(k)) * pi;
                    double theta0 = 4.0 * pow(-1.0, k) / pow(pi * (k + 0.5), 3.0);
                    double theta1 = theta0 * exp(-ss * ss * anu * t) * cos(ss * ycc);
                    theory1 -= theta1;
                }

                double error = abs(u[j] - theory1) / theory1;
                fout << ycc << "\t" << theory1 << "\t" << u[j] / u0 << "\t" << error << "\n";
            }
        }
    }

    fout.close();
}

