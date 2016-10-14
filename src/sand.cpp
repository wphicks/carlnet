#include <algorithm>
#include "sand.hpp"
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
      node.lock()->increment_value();
    }
    return true;
  }
  return false;
}

void SandNode::set_max() {
  value = std::max(0, get_rank() -1);
}
