#include <benchmark/benchmark.h>

#include <vector>

#include "ds/vector.hpp"

static void BM_dsVectorPushBack(benchmark::State& state) {
    for (auto _ : state) {
        ds::Vector<int> v;
        for (int i = 0; i < state.range(0); ++i) {
            v.PushBack(i);
        }
    }
}
BENCHMARK(BM_dsVectorPushBack)->Range(8, 8 << 10);

static void BM_stdVectorPushBack(benchmark::State& state) {
    for (auto _ : state) {
        std::vector<int> v;
        for (int i = 0; i < state.range(0); ++i) {
            v.push_back(i);
        }
    }
}
BENCHMARK(BM_stdVectorPushBack)->Range(8, 8 << 10);