#ifndef STOC_PROC_HH
#define STOC_PROC_HH

template<typename T>
class StochasticProcess
{
private:
    std::vector<T> sample;
public:
    virtual ~StochasticProcess() = default;

    virtual std::vector<T> Simulate(int) = 0;
    virtual std::vector<T> Autocov() = 0;
    virtual std::vector<T> SampleMean() = 0;
}

#endif


