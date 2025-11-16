#include "SinglyLinkedList.hpp"
#include "Iterator.hpp"

namespace ds{

SinglyLinkedList::SinglyLinkedList() noexcept: m_head(nullptr),m_size(0) {}
SinglyLinkedList::~SinglyLinkedList() noexcept { clear(); }

void SinglyLinkedList::push_front(int value) {
    m_head = new Node(value,m_head);
    ++m_size;
}

void SinglyLinkedList::push_back(int value) {
    Node* n = new Node(value);
    if (!m_head) {
        m_head = n;
    }
    else {
        Node* cur = m_head;
        while (cur->next) cur = cur->next;
        cur->next = n;
    }
    ++m_size;
}

void SinglyLinkedList::clear() noexcept {
    Node* cur = m_head;
    while (cur) {
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    m_head = nullptr;
    m_size = 0;
}

std::size_t SinglyLinkedList::size() const noexcept { return m_size; }
bool SinglyLinkedList::empty() const noexcept { return m_head == nullptr; }

Iterator SinglyLinkedList::begin() noexcept { return Iterator(m_head); }
Iterator SinglyLinkedList::end() noexcept { return Iterator(nullptr); }
Iterator SinglyLinkedList::begin() const noexcept { return Iterator(m_head); }
Iterator SinglyLinkedList::end() const noexcept { return Iterator(nullptr); }

Node* SinglyLinkedList::head() noexcept { return m_head; }
const Node* SinglyLinkedList::head() const noexcept { return m_head; }

} 
