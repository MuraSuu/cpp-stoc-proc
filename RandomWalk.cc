#include "RandomWalk.hh"

std::vector<int> RandomWalk::Simulate(int n) const
{
    std::vector<int> bernou(n);
    //TODO: Use the ranges library to make "less ugly".
    //std::generate(bernou.begin(), bernou.end(), d(g));
    for(int i = 0; i < n; ++i)
    {
        bernou[i] = d(g);
    }

    return bernou;
}

std::vector<double> MovingAverage(const RandomWalk& rw, std::size_t N)
{
    std::vector<int> sample = rw.Simulate(500);
    std::vector<double> ma;

    for(std::size_t t = N+1; t < sample.size() - N; ++t)
    {
        double sum = 0.0;
        for(std::size_t p = -N; p <= N; ++p)
        {
            sum += sample[p+t];
        }
        ma.push_back(sum/(2*N+1));
    }

    return ma;
}

std::vector<double> SampleCov(const RandomWalk& rw)
{
    std::vector<int> sample = rw.Simulate(500);
    std::vector<double> v{0.1, 0.2};
    return v;
}
