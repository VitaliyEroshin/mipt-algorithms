#include "segment-tree-rmq.hpp"
#include <cstddef>

SegmentTree::SegmentTree(size_t n)
        : size_(n),
          tree_(4 * n - 1, 0) {}

void SegmentTree::SetElement(size_t position, int value) {
    SetElement(position, value, 0, size_ - 1, 0);
}

void SegmentTree::SetElement(size_t position, int value, size_t left,
                             size_t right, size_t tree_position) {
    if (left == right) {
        tree_[tree_position] = value;
        return;
    }
    size_t mid = (left + right) / 2;

    if (position <= mid) {
        SetElement(position, value, left, mid,
                   2 * tree_position + 1);
    } else {
        SetElement(position, value, mid + 1, right,
                   2 * tree_position + 2);
    }
}

int SegmentTree::GetMin(size_t begin, size_t end) {
    return GetMin(begin, end, 0, size_ - 1, 0);
}

int SegmentTree::GetMin(size_t begin, size_t end, size_t tree_left,
                        size_t tree_right, size_t tree_position) {
    if (tree_left >= begin && tree_right < end) {
        return tree_[tree_position];
    }
    
    if (tree_left >= end || tree_right < begin) {
        return INT_MAX;
    }

    size_t mid = (tree_left + tree_right) / 2;

    int left_value = GetMin(begin, end, tree_left, mid,
                            2 * tree_position + 1);

    int right_value = GetMin(begin, end, mid + 1, tree_right,
                             2 * tree_position + 2);

    return std::min(left_value, right_value);
}