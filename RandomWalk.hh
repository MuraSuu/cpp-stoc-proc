#ifndef RANDOMWALK_H
#define RANDOMWALK_H

#include <vector>
#include <random>
#include <numeric>
#include <algorithm>

class RandomWalk
{
public:
    RandomWalk(double p) : rd(), g(rd()), d(p) {};
    std::vector<int> Simulate(int n);
private:
    std::random_device rd; //Seed.
    std::mt19937 g; //Generator.
    std::bernoulli_distribution d; //Distribution.
};

#endif


