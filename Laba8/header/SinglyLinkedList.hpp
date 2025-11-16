#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include <cstddef>
#include "Node.hpp"
#include "Iterator.hpp"   

namespace ds{

class SinglyLinkedList {
public:
    SinglyLinkedList() noexcept;
    ~SinglyLinkedList() noexcept;

    void push_front(int value);
    void push_back(int value);
    void clear() noexcept;

    std::size_t size() const noexcept;
    bool empty() const noexcept;

    Iterator begin() noexcept;
    Iterator end() noexcept;
    Iterator begin() const noexcept;
    Iterator end() const noexcept;

    Node* head() noexcept;
    const Node* head() const noexcept;

    friend class Algorithms;

private:
    Node* m_head;
    std::size_t m_size;
};
} 
#endif 
