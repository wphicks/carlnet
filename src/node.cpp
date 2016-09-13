#include <list>
#include "node.hpp"
CellNode::CellNode() :
    rank{0} {
}

CellNode::~CellNode() {
}

int CellNode::get_rank() {
  return rank;
}

void CellNode::add_neighbor(CellNode* new_neighbor) {
  if (new_neighbor != this) {
    neighbors.insert(new_neighbor);
    ++rank;
  }
}

void CellNode::remove_neighbor(CellNode* old_neighbor) {
  auto location = neighbors.find(old_neighbor);
  if (location != neighbors.end()) {
    neighbors.erase(location);
    --rank;
  }
}

bool CellNode::has_neighbor(CellNode* test_neighbor) {
  return (neighbors.find(test_neighbor) != neighbors.end());
}

bool iterate() {
  return false;
}

int get_grains() {
  return 0;
}
