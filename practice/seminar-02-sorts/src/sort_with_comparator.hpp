#pragma once

#include <vector>
#include <algorithm>

/* Сортировка со заданным компаратором */
/* x < y */
/* x == y   <=>  !(x < y) && !(y < x) */
bool Less(int x, int y) {
    return x > y;
}

void SortWithComparator(std::vector<int>& a) {
    std::sort(
        a.begin(),
        a.end(),
        Less
    );
}