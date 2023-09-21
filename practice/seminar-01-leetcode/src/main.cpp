#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <solution.hpp>
#include <support.hpp>

int GetRandomTarget(const std::vector<int>& a) {
    std::random_device device;
    std::mt19937 rng(device());

    size_t first = rng() % a.size();
    size_t shift = rng() % a.size() + 1;
    size_t second = (first + shift) % a.size();

    return a[first] + a[second];
}

bool Check(const std::vector<int>& a, int target,
           const std::pair<size_t, size_t>& answer) {
    auto [i, j] = answer;
    assert(i < a.size());
    assert(j < a.size());
    return a[i] + a[j] == target;
}

bool Test() {
    std::vector<int> a = GetRandomVector(0, 128);
    std::sort(a.begin(), a.end());
    int target = GetRandomTarget(a);

    auto answer = GetTwoSumIndices(a, target);

    if (Check(a, target, answer)) {
        std::cout << "Looks good!" << std::endl;
        return true;
    }

    std::cout << "Wrong answer." << std::endl;
    std::cout << "Array: ";
    for (auto& x : a) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::cout << "Target: " << target << std::endl;
    auto [i, j] = answer;
    std::cout << "Your answer: " << i << ' ' << j << std::endl;
    return false;
}

int main() {
    /* Uncomment next line to redirect output to io/out.txt */
    // InitIO();

    static const size_t tests_count = 16;

    for (size_t i = 0; i < tests_count; ++i) {
        std::cout << "[Test " << i << "] ";
        if (!Test()) {
            break;
        }
    }
}