#ifndef RANDOMWALK_H
#define RANDOMWALK_H

#include <vector>
#include <random>
#include <numeric>
#include <algorithm>
#include <cstdio>

//Random walk with reflective barriers.

//Simple Random walk but not necessarily symmetric.
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

std::vector<double> MovingAverage(RandomWalk& rw, int N);
std::vector<double> MovingAverage(std::vector<int>& rw, int N);
std::vector<double> SampleCov(RandomWalk& rw);

#endif


