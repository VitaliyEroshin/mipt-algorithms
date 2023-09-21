#include <vector>
#include "support.hpp"
#include "solution.hpp"

bool Test(std::ifstream& is) {
    size_t n, additional;
    is >> n >> additional;
    std::vector<int> a(n);
    ReadVector(a, is);

    std::vector<int> b(n);
    ReadVector(b, is);

    size_t real_answer;
    is >> real_answer;

    auto answer = InvokeCopyingArguments(MaximumBags, a, b, additional);
    if (answer == real_answer) {
        std::cout << "Looks good!" << std::endl;
        return true;
    }

    std::cout << "Wrong answer." << std::endl;
    std::cout << "Capacity: ";
    PrintVector(a);
    std::cout << "Rocks: ";
    PrintVector(b);
    std::cout << "Additional rocks: " << additional << std::endl;
    std::cout << "Your answer: " << answer << std::endl;
    std::cout << "Real answer: " << real_answer << std::endl;
    return false;
}

int main() {
    /* Uncomment next line to redirect output to io/out.txt */
    // InitIO();

    RunTestcases(Test, 16);
}