/*
    Leetcode: 232. Implement Queue using Stacks

    Реализуйте очередь через стеки.
*/

#pragma once

#include <stack>

class Queue {
public:
    void Push(int x) {
        in_stack_.push(x);
    }

    int Pop();
    
    int Peek();
    
    bool Empty() {
        return out_stack_.empty() && in_stack_.empty();
    }
private: 
    std::stack<int> in_stack_;
    std::stack<int> out_stack_;
};

int Queue::Pop() {
    int elem = Peek();
    out_stack_.pop();
    return elem;
}

int Queue::Peek() {
    if (out_stack_.empty()) {
        while (!in_stack_.empty()) {
            out_stack_.push(in_stack_.top());
            in_stack_.pop();
        }
    }
    return out_stack_.top();
}