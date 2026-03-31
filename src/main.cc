#include "RandomWalk.hh"
#include <cstdio>
#include <random>

int main()
{
    auto* file1 = std::fopen("rw.dat", "w+");

    if(!file1)
    {
        std::perror("File opening failed\n");
        return EXIT_FAILURE;
    }
    std::random_device rd; //Seed.
    std::mt19937 g(rd());
    std::normal_distribution<double> normal(0.0, 1.0);
    auto f = [&]() {return normal(g); };

    RandomWalk<double> gaussian_walk(0.0, f);

    gaussian_walk.Simulate(50);

    //Write down the output;

    const auto& ref = gaussian_walk.GetSamplePath();
    for(std::size_t i = 0; i < ref.size(); ++i)
    {
        std::fprintf(file1, "%ld, %.4f \n", i, ref[i]);
    }
    

    std::fclose(file1);
}
