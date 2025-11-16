#include "Iterator.hpp"
#include <stdexcept>

namespace ds{

Iterator::Iterator() noexcept: m_current(nullptr) {}
Iterator::Iterator(Node* node) noexcept: m_current(node) {}

int& Iterator::operator*() const {
    if (!m_current) throw std::runtime_error("Dereferencing end iterator");
    return m_current->value;
}

Iterator& Iterator::operator++() noexcept {
    if (m_current) m_current = m_current->next;
    return *this;
}

Iterator Iterator::operator++(int) noexcept {
    Iterator tmp(*this);
    ++(*this);
    return tmp;
}

bool Iterator::operator==(const Iterator& other) const noexcept {
    return m_current == other.m_current;
}
bool Iterator::operator!=(const Iterator& other) const noexcept {
    return !(*this == other);
}
} 
