#include <algorithm>
#include <memory>
#include "sand.hpp"

using std::static_pointer_cast;

SandNode::SandNode() :
    Node(), value{0} {
}

SandNode::~SandNode() {
}

int SandNode::get_value() {
  return value;
}

bool SandNode::increment_value() {
  ++value;
  return true;
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
  value = std::max(0, get_rank() -1);
}
