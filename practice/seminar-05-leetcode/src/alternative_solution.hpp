#pragma once

#include <vector>
#include <algorithm>

std::vector<int> FindClosestElementsBySort(std::vector<int>& arr, int k, int x) {
    sort(arr.begin(), arr.end(), [x](auto a, auto b) {
        if (abs(a - x) != abs(b - x)) {
            return abs(a - x) < abs(b - x);
        }

        return a < b;
    });

    std::vector<int> result;
    for (int i = 0; i < std::min(k, static_cast<int>(arr.size())); ++i) {
        result.push_back(arr[i]);
    }

    sort(result.begin(), result.end());

    return result;
}