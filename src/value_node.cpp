#include <algorithm>
#include <memory>
#include "value_node.hpp"

using std::static_pointer_cast;

ValueNode::ValueNode() :
    Node{}, value{0} {
}

ValueNode::~ValueNode() {
}

int ValueNode::get_value() {
  return value;
}
