#pragma once
#include "string.hpp"
#include <iostream>

class LinkedList {
public:
    struct Node {
        String value;
        Node* next{nullptr};
        explicit Node(const String& str): value(str) {}
    };

private:
    Node* head{nullptr};
    Node* tail{nullptr};

public:
    LinkedList() = default;
    LinkedList(const LinkedList& other);
    ~LinkedList();

    void pushBack(const String& str);
    bool empty() const { return head == nullptr; }
    void print() const;
};
