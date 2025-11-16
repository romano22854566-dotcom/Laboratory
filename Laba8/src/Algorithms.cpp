#include "Algorithms.hpp"

namespace ds{

Iterator Algorithms::find(SinglyLinkedList& list,int value) noexcept {
    for (auto it = list.begin(); it != list.end(); ++it)
        if (*it == value) return it;
    return list.end();
}

void Algorithms::sort_ascending(SinglyLinkedList& list) {
    if (list.empty()) return;

    Node* sorted = nullptr;
    Node* cur = list.m_head;

    while (cur) {
        Node* next = cur->next;
        if (!sorted || cur->value < sorted->value) {
            cur->next = sorted;
            sorted = cur;
        }
        else {
            Node* s = sorted;
            while (s->next && s->next->value <= cur->value) {
                s = s->next;
            }
            cur->next = s->next;
            s->next = cur;
        }
        cur = next;
    }
    list.m_head = sorted;
    list.m_size = 0;
    for (Node* n = list.m_head; n; n = n->next) ++list.m_size;
}

void Algorithms::sort_descending(SinglyLinkedList& list) {
    if (list.empty()) return;

    Node* sorted = nullptr;
    Node* cur = list.m_head;

    while (cur) {
        Node* next = cur->next;
        if (!sorted || cur->value > sorted->value) {
            cur->next = sorted;
            sorted = cur;
        }
        else {
            Node* s = sorted;
            while (s->next && s->next->value >= cur->value) {
                s = s->next;
            }
            cur->next = s->next;
            s->next = cur;
        }
        cur = next;
    }

    list.m_head = sorted;
    list.m_size = 0;
    for (Node* n = list.m_head; n; n = n->next) ++list.m_size;
}
}
