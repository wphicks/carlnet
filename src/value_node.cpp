#include <algorithm>
#include <memory>
#include "value_node.hpp"

using std::static_pointer_cast;

ValueNode::ValueNode() :
    Node(), value{0} {
}

ValueNode::~ValueNode() {
}

int ValueNode::get_value() {
  return value;
}

bool ValueNode::increment_value() {
  ++value;
  return true;
}

bool ValueNode::iterate() {
  if (get_rank() <= get_value()) {
    value -= get_rank();
    for (auto node : neighbors) {
      shared_ptr<ValueNode> valued_node = static_pointer_cast<ValueNode>(
        node.lock());
      valued_node->increment_value();
    }
    return true;
  }
  return false;
}

void ValueNode::set_max() {
  value = std::max(0, get_rank() -1);
}
