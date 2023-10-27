#include <queue>
#include <vector>
#include "alternative_solution.hpp"
#include "support.hpp"
#include "solution.hpp"

bool Test() {
    auto arr = GetRandomVector(0, 100, 50);
    auto k = GetRandomInt(0, arr.size());
    auto x = GetRandomInt(0, 100);

    auto result = InvokeCopyingArguments(FindClosestElements, arr, k, x);
    auto real_result = InvokeCopyingArguments(FindClosestElementsBySort, arr, k, x);

    if (result != real_result) {
        std::cout << "Arr: ";
        PrintVector(arr);
        std::cout << "k: " << k;
        std::cout << "x: " << x;
        return false;
    }
    return true;
}

int main() {
    /* Uncomment next line to redirect output to io/out.txt */
    // InitIO();

    static const size_t num_tests = 16;
    for (size_t i = 0; i < num_tests; ++i) {
        std::cout << "[Test " << i << "] ";
        if (Test()) {
            std::cout << "Good!" << std::endl;
        } else {
            std::cout << "Wrong Answer :/";
            break;
        }
    }
}