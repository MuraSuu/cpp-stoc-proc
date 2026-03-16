#include "RandomWalk.hh"
#include <cstdio>

int main()
{
    auto* file = std::fopen("poisson.dat", "w+");
    if(!file)
    {
        std::perror("File opening failed\n");
        return EXIT_FAILURE;
    }

    RandomWalk rw(0.3);
    auto walk = rw.Simulate(10);
    std::printf("simulated\n");
    auto ma = MovingAverage(rw, 3);
    for(int i =0; i < walk.size(); ++i)
    {
        std::fprintf(file, "%d %.5f\n", i, walk[i]);
    }
    std::fclose(file);
}
