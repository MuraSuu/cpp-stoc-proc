#ifndef RANDOMWALK_H
#define RANDOMWALK_H

#include <vector>
#include <random>
#include <numeric>
#include <algorithm>

//Random walk with reflective barriers.

//Simple Random walk but not necessarily symmetric.
class RandomWalk
{
public:
    RandomWalk(double p) : rd(), g(rd()), d(p) {};
    std::vector<int> Simulate(int n) const;
private:
    std::random_device rd; //Seed.
    mutable std::mt19937 g; //Generator.
    mutable std::bernoulli_distribution d; //Distribution.
};

std::vector<double> MovingAverage(const RandomWalk& rw, std::size_t N);
std::vector<double> SampleCov(const RandomWalk& rw);

#endif


