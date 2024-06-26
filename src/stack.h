#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>

class Stack {
private:
    std::vector<int> data_vec;
public:
    // Push element onto stack
    void push(int data);

    // Check if the stack is empty
    bool isEmpty() const;

    // Pop element from stack
    int pop();

    // Peek at the top element of stack
    int peek() const;
};


