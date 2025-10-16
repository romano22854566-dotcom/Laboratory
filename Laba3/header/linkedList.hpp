#pragma once
#include "string.hpp"

class LinkedList {
private:
    struct Node {
        String string;
        double data;
        Node* next;
        Node(const String& str,double value);
    };

    Node* head;
    Node* tail;

public:
    LinkedList();
    LinkedList(const LinkedList& other);
    ~LinkedList();

    LinkedList& operator=(const LinkedList& other) = delete;
   
    void pushBack(const String& string,double data);
    void pushBack(const char* string,double data);
    Node* find(const String& key) const;
    void print() const;
};
