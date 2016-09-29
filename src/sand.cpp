#include "sand.hpp"
SandNode::SandNode() :
    CellNode(), value{0} {
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
