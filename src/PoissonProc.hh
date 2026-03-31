#ifndef POISSON_HH
#define POISSON_HH

#include <vector>
#include <random>

class Poisson
{
public:
    Poisson(int lambda) : g(rd()), p(lambda) {};
    std::vector<double> Simulate(std::size_t n);
private:
    std::random_device rd; //Seed.
    std::mt19937 g; //Generator.
    std::poisson_distribution<> p;
};

#endif


