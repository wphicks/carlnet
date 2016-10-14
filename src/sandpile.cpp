#include <memory>
#include <vector>
#include "sandpile.hpp"
#include "random_helper.hpp"
#include "node.hpp"

using std::make_shared;
using std::vector;

SandPile::SandPile() : size{0} {
  sink = make_shared<Node>();
}

SandPile::SandPile(int num_nodes) : SandPile{} {
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

int SandPile::iterate_without_source() {
  int avalanches = 0;
  for (auto node_ : nodes) {
    if (node_->iterate() && node_->get_rank()) {
      ++avalanches;
    }
  }
  return avalanches;
}

int SandPile::iterate() {
  nodes[randint(size-1)]->increment_value();  // Add grain to rand node
  return iterate_without_source();
}

vector<shared_ptr<SandNode>>::const_iterator SandPile::begin() {
  return nodes.cbegin();
}

vector<shared_ptr<SandNode>>::const_iterator SandPile::end() {
  return nodes.cend();
}

void SandPile::set_max() {
  for (auto node_ : nodes) {
    node_->set_max();
  }
}

const shared_ptr<Node> SandPile::get_sink() {
  return sink;
}
