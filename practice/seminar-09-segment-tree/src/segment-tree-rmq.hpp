/*
    Segment Tree: Range Minimum Query.

    Author: 
*/

#pragma once
#include <cstddef> // size_t
#include <vector>

class SegmentTree {
public:
    SegmentTree(size_t n);
    
    void SetElement(size_t position, int value);

    int GetMin(size_t begin, size_t end);

    void SetSegment(size_t /*begin*/, size_t /*end*/, int /*value*/) {};
private:
    size_t size_;
    std::vector<int> tree_;

    void SetElement(size_t position, int value,
                    size_t left, size_t right, size_t tree_position);

    int GetMin(size_t begin, size_t end, size_t tree_left,
               size_t tree_right, size_t tree_position);
};
