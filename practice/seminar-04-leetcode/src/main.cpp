#include <queue>
#include <vector>
#include "support.hpp"
#include "solution.hpp"

bool Test() {
    Queue users_queue;
    std::queue<int> std_queue;

    auto values = GetRandomVector(-5, 5, 10);

    while (!values.empty()) {
        int operation = GetRandomInt(0, 3);
        if (operation == 0) {
            int value = values.back();
            values.pop_back();

            users_queue.Push(value);
            std_queue.push(value);

            continue;
        }
        
        if (operation == 1) {
            if (std_queue.empty() != users_queue.Empty()) {
                return false;
            }
            continue;
        }

        if (std_queue.empty()) {
            continue;
        }
        int real_value = std_queue.front();
        int users_value;

        if (operation == 2) {
            users_value = users_queue.Peek();
        } else {
            users_value = users_queue.Pop();
            std_queue.pop();
        }

        if (users_value != real_value) {
            return false;
        }
    }

    return true;
}

int main() {
    /* Uncomment next line to redirect output to io/out.txt */
    // InitIO();

    static const size_t num_tests = 16;
    for (size_t i = 0; i < num_tests; ++i) {
        std::cout << "[Test " << i << "] ";
        if (Test()) {
            std::cout << "Good!" << std::endl;
        } else {
            std::cout << "Wrong Answer :/";
            break;
        }
    }
}