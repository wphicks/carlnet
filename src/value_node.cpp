#include "value_node.hpp"

ValueNode::ValueNode() :
    Node{}, value{0} {
}

ValueNode::~ValueNode() {
}

int ValueNode::get_value() {
  return value;
}
