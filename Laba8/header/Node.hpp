#ifndef NODE_HPP
#define NODE_HPP

namespace ds{

struct Node {
    int value;
    Node* next;

    Node(int v,Node* n = nullptr) noexcept;
    ~Node() noexcept;
};
} 
#endif 
