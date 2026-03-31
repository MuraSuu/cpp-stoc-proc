#ifndef RANDOMWALK_H
#define RANDOMWALK_H

#include <cmath>
#include <cstddef>
#include <functional>
#include <deque>

#include <numeric>
#include <cmath>
#include <cstdio>

//Random walk with reflective barriers.

template <typename StateType>
class RandomWalk
{
public:
    using Increment = std::function<StateType()>;

    RandomWalk(StateType x0, Increment inc_) : inc(inc_)
    {
        sample_path.push_back(x0);
    }
    
    void Simulate(int n); //Generates n more samples.
    const std::deque<StateType>& GetSamplePath() const;
    void CleanUp(); //Deletes current sample path.
    
    float SampleMean();
    float SampleSTD();
    
    //std::deque<double> MovingAverage(int N);
    //std::deque<double> SampleCov(int N);
private:
    Increment inc;
    std::deque<StateType> sample_path;
};

template<typename StateType>
void RandomWalk<StateType>::Simulate(int n)
{
    for(int i = 0; i < n; ++i)
    {   
        StateType next = sample_path.back() + inc();
        sample_path.push_back(next);
    }
}

template<typename StateType>
const std::deque<StateType>& RandomWalk<StateType>::GetSamplePath() const { return sample_path; }

template<typename StateType>
void RandomWalk<StateType>::CleanUp() { sample_path.clear(); }
    
template<typename StateType>
float RandomWalk<StateType>::SampleMean()
{
    if(sample_path.size() == 0)
    {
        return 0;
    }

    float sum = std::accumulate(sample_path.begin(), sample_path.end(), 0.0);
    return sum/sample_path.size();
}

template<typename StateType>
float RandomWalk<StateType>::SampleSTD()
{
    if(sample_path.size() <= 1)
    {
        return 0.0;
    }

    float mean = SampleMean();
    float sum = 0.0;
    std:size_t N = sample_path.size();

    for(auto xi : sample_path)
    {
        sum += (xi - mean)*(xi-mean)/(N - 1);
    }

    return std::sqrt(sum);
}

#endif


