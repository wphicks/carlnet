#include <memory>
#include <algorithm>
#include <utility>
#include "node.hpp"
using std::shared_ptr;
using std::find_if;
using std::swap;

CellNode::CellNode() :
    rank{0} {
}

CellNode::~CellNode() {
}

int CellNode::get_rank() {
  return rank;
}

void CellNode::add_neighbor(shared_ptr<CellNode> new_neighbor, bool mutual) {
  if (
      new_neighbor.get() != this &&
      !(this->has_neighbor(new_neighbor)) ) {
    neighbors.push_back(new_neighbor);
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
  auto location = find_if(
      neighbors.begin(), neighbors.end(),
      [old_neighbor] (weak_ptr<CellNode> elem) {return elem.lock() == old_neighbor;}
  );
  if (location != neighbors.end()) {
    if (location != neighbors.end() - 1) {
      swap(*location, neighbors.back());
    }
    neighbors.pop_back();
    --rank;

    if (mutual) {
      old_neighbor->remove_neighbor(shared_from_this());
    }
  }
}

void CellNode::remove_neighbor(shared_ptr<CellNode> old_neighbor) {
  return remove_neighbor(old_neighbor, false);
}

bool CellNode::has_neighbor(shared_ptr<CellNode> test_neighbor) {
  return (
      find_if(
        neighbors.begin(), neighbors.end(),
        [test_neighbor] (weak_ptr<CellNode> elem) {return elem.lock() == test_neighbor;}
      ) != neighbors.end()
  );
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
