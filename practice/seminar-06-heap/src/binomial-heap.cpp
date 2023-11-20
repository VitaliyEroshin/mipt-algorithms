#include "binomial-heap.hpp"

int BinomialHeap::GetMin() {
    int min = trees_[0]->value;
    for (size_t i = 1; i < trees_.size(); ++i) {
        min = std::min(trees_[i]->value, min);
    }
    return min;
}

BinomialHeap::Node* BinomialHeap::MergeTrees(Node* main, Node* additional){
    if (main->value > additional->value) {
        std::swap(main, additional);
    }
    additional->right = main->left_child;
    main->left_child->left = additional;
    main->left_child = additional;
    additional->parent = main;
    main->rank++;
    return main;
}

void BinomialHeap::Merge(BinomialHeap heap) {
    size_t i = 0;
    size_t j = 0;
    std::vector<Node*> new_heap;
    while (i < trees_.size() && j < heap.trees_.size()) {
        if (trees_[i]->rank == heap.trees_[j]->rank) {
            trees_[i] = MergeTrees(trees_[i], heap.trees_[j]);
            j++;
            continue;
        }
        if (trees_[i]->rank < heap.trees_[j]->rank) {
            new_heap.push_back(trees_[i]);
            i++;
        } else {
            new_heap.push_back(heap.trees_[j]);
            j++;
        }
    }

    while (i < trees_.size()) {
        new_heap.push_back(trees_[i]);
        i++;
    }

    while (j < heap.trees_.size()) {
        new_heap.push_back(heap.trees_[j]);
        j++;
    }
    trees_ = new_heap;
}