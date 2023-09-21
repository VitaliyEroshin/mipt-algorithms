#include "support.hpp"
#include "sort.hpp"
#include "sort_with_comparator.hpp"
#include "sort_with_lambda_comparator.hpp"

void PrintSorted(std::vector<int> a, auto sort, std::string sort_name) {
    sort(a);

    std::cout << "Sorted array (with " << sort_name << ")" << std::endl;
    for (auto x : a) {
        std::cout << x << ' ';
    }

    std::cout << std::endl;
    std::cout << std::endl;
}

void RunSorts() {
    std::vector<int> a = GetRandomVector(-9, 9, 7);
    std::cout << "Initial array:" << std::endl;
    for (auto x : a) {
        std::cout << x << ' ';
    };
    std::cout << std::endl << std::endl;

    PrintSorted(a, Sort, "no comparator");
    PrintSorted(a, SortWithComparator, "function comparator");
    PrintSorted(a, SortWithLambdaComparator, "lambda comparator");
}

int main() {
    /* Uncomment next line to redirect output to io/out.txt */
    // InitIO();

    RunSorts();
}