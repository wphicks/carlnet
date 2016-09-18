#include <memory>
#include "node.hpp"
using std::shared_ptr;

CellNode::CellNode() :
    rank{0} {
}

CellNode::~CellNode() {
}

int CellNode::get_rank() {
  return rank;
}

void CellNode::add_neighbor(shared_ptr<CellNode> new_neighbor) {
  if (new_neighbor.get() != this) {
    neighbors.insert(new_neighbor);
    ++rank;
  }
}

void CellNode::remove_neighbor(shared_ptr<CellNode> old_neighbor) {
  auto location = neighbors.find(old_neighbor);
  if (location != neighbors.end()) {
    neighbors.erase(location);
    --rank;
  }
}

bool CellNode::has_neighbor(shared_ptr<CellNode> test_neighbor) {
  return (neighbors.find(test_neighbor) != neighbors.end());
}

bool CellNode::iterate() {
  return false;
}

int CellNode::get_value() {
  return 0;
}

bool CellNode::increment_value() {
  return false;
}
