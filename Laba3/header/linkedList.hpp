#pragma once
#include "string.hpp"
#include <iostream>

class LinkedList {
public:
    struct Node {
        String value;
        Node* next;
        explicit Node(const String& str);
    };

private:
    Node* head;
    Node* tail;

public:
    LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);
    LinkedList(LinkedList&& other) noexcept;
    LinkedList& operator=(LinkedList&& other) noexcept;
    ~LinkedList();

    void pushBack(const String& str);
    bool empty() const;
    void print() const;
};
