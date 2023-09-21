#pragma once

#include <vector>
#include <algorithm>

/* Сортировка с компаратором, заданным через лямбда-выражение */
void SortWithLambdaComparator(std::vector<int>& a) {
    std::sort(
        a.begin(),
        a.end(),
        [](int x, int y) {
            return std::abs(x) < std::abs(y);
        }
    );
}