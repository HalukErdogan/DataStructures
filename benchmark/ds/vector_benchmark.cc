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

static void BM_dsVectorErase(benchmark::State& state) {
    for (auto _ : state) {
        ds::Vector<int> v;
        for (int i = 0; i < state.range(0); ++i) {
            v.PushBack(i);
        }
        for (int i = state.range(0) - 1; i >= 0; --i) {
            v.Erase(i);
        }
    }
}
BENCHMARK(BM_dsVectorErase)->Range(8, 8<<10);

static void BM_stdVectorErase(benchmark::State& state) {
    for (auto _ : state) {
        std::vector<int> v;
        for (int i = 0; i < state.range(0); ++i) {
            v.push_back(i);
        }
        for (int i = state.range(0) - 1; i >= 0; --i) {
            v.erase(v.begin() + i);
        }
    }
}
BENCHMARK(BM_stdVectorErase)->Range(8, 8<<10);

static void BM_dsVectorInsert(benchmark::State& state) {
    for (auto _ : state) {
        ds::Vector<int> v;
        for (int i = 0; i < state.range(0); ++i) {
            v.Insert(i / 2, i);
        }
    }
}
BENCHMARK(BM_dsVectorInsert)->Range(8, 8<<10);

static void BM_stdVectorInsert(benchmark::State& state) {
    for (auto _ : state) {
        std::vector<int> v;
        for (int i = 0; i < state.range(0); ++i) {
            v.insert(v.begin() + i / 2, i);
        }
    }
}
BENCHMARK(BM_stdVectorInsert)->Range(8, 8<<10);