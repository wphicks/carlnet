#include "sand.hpp"
SandNode::SandNode() :
    CellNode(), grains{0} {
}

int SandNode::get_grains() {
  return grains;
}
