#include "Poisson.hh"

std::vector<double> Poisson::Simulate(std::size_t n)
{
    std::vector<double> sample(n);
    for(double& i : sample)
    {
        i = p(g);
    }
    return sample;
}
