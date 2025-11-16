#include "Node.hpp"

namespace ds{
Node::Node(int v,Node* n) noexcept: value(v),next(n) {}
Node::~Node() noexcept = default;
}
