#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "Node.hpp"

namespace ds{

class Iterator {
public:
    Iterator() noexcept;
    explicit Iterator(Node* node) noexcept;

    int& operator*() const;
    Iterator& operator++() noexcept;
    Iterator operator++(int) noexcept;

    bool operator==(const Iterator& other) const noexcept;
    bool operator!=(const Iterator& other) const noexcept;

private:
    Node* m_current;
};
} 
#endif 
