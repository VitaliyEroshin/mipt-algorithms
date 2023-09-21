#pragma once

#include <utility>
#include <vector>

std::pair<size_t, size_t> GetTwoSumIndices(std::vector<int>& a, int target) {
    // Your code goes here

    int i = 0;
    int j = a.size() - 1;
    while (i < j) {
        if (a[i] + a[j] < target) {
            i += 1;
        } else if (a[i] + a[j] > target) {
            j -= 1;
        } else {
            return {i, j};
        }
    }

    return {0, 0};
}