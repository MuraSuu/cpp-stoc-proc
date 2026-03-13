#include "RandomWalk.hh"

std::vector<int> RandomWalk::Simulate(int n)
{
    std::vector<int> bernou(n);
    //std::generate(bernou.begin(), bernou.end(), d(g));
    for(int i = 0; i < n; ++i)
    {
        bernou[i] = d(g);
    }

    return bernou;
}
