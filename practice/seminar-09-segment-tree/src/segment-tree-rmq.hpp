/*
    Segment Tree: Range Minimum Query.

    Author: 
*/

#pragma once
#include <cstddef> // size_t

class SegmentTree {
public:
    SegmentTree(size_t n);

    void SetElement(size_t position, int value);

    int GetMin(size_t begin, size_t end);

    void SetSegment(size_t /*begin*/, size_t /*end*/, int /*value*/) {};
private:
};