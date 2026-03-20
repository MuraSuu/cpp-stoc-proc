#include "RandomWalk.hh"
#include <cstdio>

int main()
{
    auto* file1 = std::fopen("rw.dat", "w+");
    auto* file2 = std::fopen("ma.dat", "w+");
    if(!file1 || !file2)
    {
        std::perror("File opening failed\n");
        return EXIT_FAILURE;
    }

    RandomWalk rw(0.5);
    auto walk = rw.Simulate(500);
    std::printf("simulated\n");
    std::vector<double> ma = MovingAverage(walk, 5);
    
    for(int i =0; i < walk.size(); ++i)
    {
        std::fprintf(file1, "%d %d\n", i, walk[i]);
        
    }

    for(int i = 0; i < ma.size(); ++i)
    {
        std::fprintf(file2, "%d %.4f\n", i, ma[i]);
    }

    std::fclose(file1);
    std::fclose(file2);
}
