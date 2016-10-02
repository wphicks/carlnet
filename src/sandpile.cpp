#include <memory>
#include <vector>
#include "sandpile.hpp"

using std::make_shared;
using std::vector;

SandPile::SandPile() : size{1} {
}

SandPile::SandPile(int num_nodes) : size{1} {
  for (int i=0; i < num_nodes - 1; ++i) {
    add_node(make_shared<SandNode>());
  }
}

int SandPile::get_size() {
  return size;
}

void SandPile::add_node(shared_ptr<SandNode> new_node) {
  nodes.push_back(new_node);
  ++size;
}

int SandPile::iterate() {
  int avalanches = 0;
  for (auto node_ : nodes) {
    if (node_->iterate() && node_->get_rank()) {
      ++avalanches;
    }
  }
  return avalanches;
}

vector<shared_ptr<SandNode>>::const_iterator SandPile::begin() {
  return nodes.cbegin();
}

vector<shared_ptr<SandNode>>::const_iterator SandPile::end() {
  return nodes.cend();
}
