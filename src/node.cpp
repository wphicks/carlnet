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

void CellNode::add_neighbor(shared_ptr<CellNode> new_neighbor, bool mutual) {
  if (new_neighbor.get() != this) {
    neighbors.insert(new_neighbor);
    ++rank;
  }
  if (mutual) {
    new_neighbor->add_neighbor(shared_from_this());
  }
}

void CellNode::add_neighbor(shared_ptr<CellNode> new_neighbor) {
  return add_neighbor(new_neighbor, false);
}

void CellNode::remove_neighbor(shared_ptr<CellNode> old_neighbor, bool mutual) {
  auto location = neighbors.find(old_neighbor);
  if (location != neighbors.end()) {
    neighbors.erase(location);
    --rank;
  }
  if (mutual) {
    old_neighbor->remove_neighbor(shared_from_this());
  }
}

void CellNode::remove_neighbor(shared_ptr<CellNode> old_neighbor) {
  return remove_neighbor(old_neighbor, false);
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
