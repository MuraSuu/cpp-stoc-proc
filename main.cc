#include "Poisson.hh"
#include <cstdio>

int main()
{
    auto* file = std::fopen("poisson.dat", "w+");
    if(!file)
    {
        std::perror("File opening failed\n");
        return EXIT_FAILURE;
    }

    Poisson rw(3);
    auto walk = rw.Simulate(10);
    for(int i =0; i < walk.size(); ++i)
    {
        std::fprintf(file, "%d %.5f\n", i, walk[i]);
    }
    std::fclose(file);
}
