/*
    Leetcode: 2279. Maximum Bags With Full Capacity of Rocks

    Даны n мешков с камнями. Про i-тый мешок мы знаем,
    что в него помещается capacity[i] камней, и что
    сейчас в нем лежит rocks[i] камней. Также нам дано
    additionalRocks камней, и мы хотим разложить эти
    камни по мешкам так, чтобы количество заполненых
    мешков было максимально.
*/

#pragma once

#include <vector>
#include <algorithm>

size_t MaximumBags(std::vector<int>& capacity,
                std::vector<int>& rocks,
                int additional_rocks) {
    
    size_t n = capacity.size(); 

    std::vector<int> diff(n);
    for (size_t i = 0; i < n; ++i) {
        diff[i] = capacity[i] - rocks[i];
    }

    sort(diff.begin(), diff.end());
    
    size_t full_bags = 0;
    size_t cur_bag = 0;
    while (cur_bag < n && additional_rocks - diff[cur_bag] >= 0) {
        additional_rocks -= diff[cur_bag];
        ++full_bags;
        ++cur_bag;
    }

    return full_bags;
}