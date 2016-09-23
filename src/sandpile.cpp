#include <memory>
#include "sandpile.hpp"

using std::make_shared;

SandPile::SandPile() : size{0} {
}

SandPile::SandPile(int num_nodes) : size{0} {
  for (int i=0; i < num_nodes; ++i) {
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
