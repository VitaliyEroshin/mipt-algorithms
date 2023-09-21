#include "support.hpp"
#include "solution.hpp"

bool Test(std::ifstream& is) {
    size_t n;
    is >> n;
    std::vector<int> a(n);
    ReadVector(a, is);

    int real_answer;
    is >> real_answer;

    auto answer = InvokeCopyingArguments(LargestPerimeter, a);

    if (answer == real_answer) {
        std::cout << "Looks good!" << std::endl;
        return true;
    }

    std::cout << "Wrong answer." << std::endl;
    std::cout << "Array: ";
    PrintVector(a);
    std::cout << "Your answer: " << answer << std::endl;
    std::cout << "Real answer: " << real_answer << std::endl;
    return false;
}

int main() {
    /* Uncomment next line to redirect output to io/out.txt */
    // InitIO();

    RunTestcases(Test, 16);
}