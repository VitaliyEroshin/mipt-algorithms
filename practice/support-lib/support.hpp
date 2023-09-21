#pragma once

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <fstream>
#include <functional>
#include <iostream>
#include <random>

void InitIO() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef local
    freopen("../io/in.txt", "r", stdin);
    freopen("../io/out.txt", "w", stdout);
#endif
}

std::vector<int> GetRandomVector(int min_number = 0, int max_number = 0,
                                 size_t size = 10) {
    std::random_device device;
    std::mt19937 rng(device());
    std::uniform_int_distribution uniform(min_number, max_number);

    std::vector<int> a(size);
    for (auto& x : a) {
        x = uniform(rng);
    }

    return a;
}

int GetRandomInt(int min_number = 0, int max_number = 10) {
    std::random_device device;
    std::mt19937 rng(device());
    std::uniform_int_distribution uniform(min_number, max_number);

    return uniform(rng);
}

std::vector<int> GetSmallerRandomVector(std::vector<int> larger) {
    std::random_device device;
    std::mt19937 rng(device());

    std::vector<int> smaller(larger.size());

    auto larger_element = larger.begin();
    for (auto& x : smaller) {
        std::uniform_int_distribution uniform(0, *larger_element);
        ++larger_element;
        x = uniform(rng);
    }

    return smaller;
}

template <typename F, typename... Args>
static auto InvokeCopyingArguments(F&& f, Args... args) {
    return f(args...);
}

template <typename T>
void PrintVector(std::vector<T>& a) {
    for (auto& x : a) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
void ReadVector(std::vector<T>& a, std::ifstream& is) {
    for (auto& x : a) {
        is >> x;
    }
}

template <typename Test>
auto RunTestcases(Test&& test, size_t tests_count,
                  std::string testcase_path = "../io/tests.txt") {
    std::ifstream testcase;
    testcase.open(testcase_path);

    for (size_t i = 0; i < tests_count; ++i) {
        std::cout << "[Test " << i << "] ";
        if (!test(testcase)) {
            return false;
        }
    }

    return true;
}