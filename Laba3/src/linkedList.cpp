#include "linkedList.hpp"

LinkedList::LinkedList(const LinkedList& other) {
    Node* cur = other.head;
    while (cur) {
        pushBack(cur->value);
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

void LinkedList::pushBack(const String& str) {
    Node* node = new Node(str);
    if (!head) {
        head = tail = node;
    }
    else {
        tail->next = node;
        tail = node;
    }
}

void LinkedList::print() const {
    Node* cur = head;
    while (cur) {
        std::cout << "  - " << cur->value.cStr() << '\n';
        cur = cur->next;
    }
}
