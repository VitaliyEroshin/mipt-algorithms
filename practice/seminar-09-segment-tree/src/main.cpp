#include "support.hpp"
#include "segment-tree-rmq.hpp"

void TestSetElement() {
    std::vector<int> a(50, 0);
    SegmentTree t(50);

    for (size_t i = 0; i < 100; ++i) {
        if (i % 3 == 0) {
            int value = GetRandomInt(0, 25);
            size_t position = GetRandomInt(0, 49);

            t.SetElement(position, value);
            a[position] = value;
            continue;
        }
        size_t begin = GetRandomInt(0, 49);
        size_t end = GetRandomInt(0, 49);
        if (begin > end) {
            std::swap(begin, end);
        }

        ++end;

        int tree_min = t.GetMin(begin, end);
        bool found = false;
        for (size_t j = begin; j < end; ++j) {
            if (a[j] < tree_min) {
                std::cout << "Your min is greater than real." << std::endl;
                return;
            }

            if (a[j] == tree_min) {
                found = true;
            }
        }

        if (!found) {
            std::cout << "Your min is less than real." << std::endl;
            return;
        }
    }

    std::cout << "First level passed!" << std::endl;
}

void TestSetSegment() {
    std::vector<int> a(50, 0);
    SegmentTree t(50);

    for (size_t i = 0; i < 100; ++i) {
        if (i % 3 == 0) {
            int value = GetRandomInt(0, 25);
            
            size_t begin = GetRandomInt(0, 49);
            size_t end = GetRandomInt(0, 49);
            if (begin > end) {
                std::swap(begin, end);
            }

            ++end;

            t.SetSegment(begin, end, value);
            for (size_t j = begin; j < end; ++j) {
                a[j] = value;
            }
            continue;
        }
        size_t begin = GetRandomInt(0, 49);
        size_t end = GetRandomInt(0, 49);
        if (begin > end) {
            std::swap(begin, end);
        }

        ++end;

        int tree_min = t.GetMin(begin, end);
        bool found = false;
        for (size_t j = begin; j < end; ++j) {
            if (a[j] < tree_min) {
                std::cout << "Your min is greater than real." << std::endl;
                return;
            }

            if (a[j] == tree_min) {
                found = true;
            }
        }

        if (!found) {
            std::cout << "Your min is less than real." << std::endl;
            return;
        }
    }

    std::cout << "First level passed!" << std::endl;
}

int main() {
    /* Uncomment next line to redirect output to io/out.txt */
    // InitIO();

    TestSetElement();
    // TestSetSegment(); // Bonus
}