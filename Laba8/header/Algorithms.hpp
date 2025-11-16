#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "SinglyLinkedList.hpp"

namespace ds{

class Algorithms {
public:
    static Iterator find(SinglyLinkedList& list,int value) noexcept;
    static void sort_ascending(SinglyLinkedList& list);
    static void sort_descending(SinglyLinkedList& list);
};

} 
#endif 
