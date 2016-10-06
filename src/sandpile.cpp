#include <memory>
#include <vector>
#include "sandpile.hpp"

using std::make_shared;
using std::vector;

SandPile::SandPile() : size{0} {
    add_node(make_shared<SandNode>());
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
  auto node_iter = nodes.begin();
  ++node_iter;  // First node is the sink node; never iterates
  // TODO: Add sources
  int avalanches = 0;
  for (auto end_iter = nodes.end(); node_iter != end_iter; ++node_iter) {
    if ((*node_iter)->iterate() && (*node_iter)->get_rank()) {
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
