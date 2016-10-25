#include <algorithm>
#include "sand_node.hpp"
SandNode::SandNode() :
    IntNode{} {
}

SandNode::~SandNode() {
}

void SandNode::increment_value() {
  ++value;
}

bool SandNode::iterate() {
  if (get_rank() <= get_value()) {
    value -= get_rank();
    for (auto node : neighbors) {
      shared_ptr<SandNode> valued_node = static_pointer_cast<SandNode>(
        node.lock());
      valued_node->increment_value();
    }
    return true;
  }
  return false;
}

void SandNode::set_max() {
  value = std::max(0, get_rank() - 1);
}
