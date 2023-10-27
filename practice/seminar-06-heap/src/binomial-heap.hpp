#pragma once
#include <vector>
/*
    Binomial Heap.

    Author: OlyaksandrDmitrievitchEvseev
*/

class BinomialHeap {
  public:
    int GetMin();
    void ExtractMin();
    void Insert(int element);
    void Merge(BinomialHeap heap);

  private:
    struct Node {
        int value;
        Node* parent;
        Node* left;
        Node* right;
        Node* left_child;
        int rank;
    };
    std::vector<Node*> trees_;
    Node* MergeTrees(Node* main, Node* additional);
};