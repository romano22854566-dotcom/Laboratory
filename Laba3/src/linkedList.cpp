#include "linkedList.hpp"
#include <iostream>
#include <cstring>

LinkedList::Node::Node(const String& str,double value)
    : string(str),data(value),next(nullptr) {
}

LinkedList::LinkedList(): head(nullptr),tail(nullptr) {}

LinkedList::LinkedList(const LinkedList& other): head(nullptr),tail(nullptr) {
    Node* cur = other.head;
    while (cur) {
        pushBack(cur->string,cur->data);
        cur = cur->next;
    }
}

LinkedList::~LinkedList() {
    Node* cur = head;
    while (cur) {
        Node* tmp = cur->next;
        delete cur;
        cur = tmp;
    }
}

void LinkedList::pushBack(const String& string,double data) {
    Node* node = new Node(string,data);
    if (!head) {
        head = tail = node;
    }
    else {
        tail->next = node;
        tail = node;
    }
}

void LinkedList::pushBack(const char* string,double data) {
    String s(string);
    pushBack(s,data);
}

LinkedList::Node* LinkedList::find(const String& key) const {
    Node* cur = head;
    while (cur) {
        if (std::strcmp(cur->string.cStr(),key.cStr()) == 0) {
            return cur;
        }
        cur = cur->next;
    }
    return nullptr;
}

void LinkedList::print() const {
    Node* cur = head;
    while (cur) {
        std::cout << "  - " << cur->string.cStr() << std::endl;
        cur = cur->next;
    }
}
