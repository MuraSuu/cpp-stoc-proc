#include "RandomWalk.hh"

std::vector<int> RandomWalk::Simulate(int n) 
{
    std::vector<int> bernou(n);
    std::generate(bernou.begin(), bernou.end(), [&]() { bool res = d(g); return res ? 1 : -1; });
    std::partial_sum(bernou.cbegin(), bernou.cend(), bernou.begin());
    return bernou;
}

std::vector<double> MovingAverage(RandomWalk& rw, int N)
{
    std::vector<int> sample = rw.Simulate(500);
    std::vector<double> ma;
    for(int t = N+1; t < sample.size() - N; ++t)
    {
        double sum = 0.0;
        for(int p = -N; p <= N; ++p)
        {
            sum += sample[p+t];
        }
        ma.push_back(sum/(2*N+1));
    }

    return ma;
}

std::vector<double> MovingAverage(std::vector<int>& sample, int N)
{
    std::vector<double> ma;
    for(int t = N+1; t < sample.size() - N; ++t)
    {
        double sum = 0.0;
        for(int p = -N; p <= N; ++p)
        {
            sum += sample[p+t];
        }
        ma.push_back(sum/(2*N+1));
    }

    return ma;
}
