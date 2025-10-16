#include "linkedList.hpp"

LinkedList::Node::Node(const String& str): value(str),next(nullptr) {}

LinkedList::LinkedList(): head(nullptr),tail(nullptr) {}

LinkedList::LinkedList(const LinkedList& other): head(nullptr),tail(nullptr) {
    auto* cur = other.head;
    while (cur) {
        pushBack(cur->value);
        cur = cur->next;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this != &other) {
        this->~LinkedList();
        head = tail = nullptr;
        auto* cur = other.head;
        while (cur) {
            pushBack(cur->value);
            cur = cur->next;
        }
    }
    return *this;
}

LinkedList::LinkedList(LinkedList&& other) noexcept
    : head(other.head),tail(other.tail) {
    other.head = nullptr;
    other.tail = nullptr;
}

LinkedList& LinkedList::operator=(LinkedList&& other) noexcept {
    if (this != &other) {
        this->~LinkedList();
        head = other.head;
        tail = other.tail;
        other.head = nullptr;
        other.tail = nullptr;
    }
    return *this;
}

LinkedList::~LinkedList() {
    auto* cur = head;
    while (cur) {
        auto* tmp = cur->next;
        delete cur;
        cur = tmp;
    }
}

void LinkedList::pushBack(const String& str) {
    auto* node = new Node(str);
    if (!head) {
        head = tail = node;
    }
    else {
        tail->next = node;
        tail = node;
    }
}

bool LinkedList::empty() const {
    return head == nullptr;
}

void LinkedList::print() const {
    auto* cur = head;
    while (cur) {
        std::cout << "  - " << cur->value.cStr() << '\n';
        cur = cur->next;
    }
}
