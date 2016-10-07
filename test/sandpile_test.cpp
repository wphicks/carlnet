#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE sandpile_test
#include <set>
#include <memory>
#include <boost/test/included/unit_test.hpp>
#include "sand.hpp"
#include "sandpile.hpp"

using std::set;
using std::make_shared;

struct SandPileFixture {
  shared_ptr<SandNode> node0 = make_shared<SandNode>();
  shared_ptr<SandNode> node1 = make_shared<SandNode>();
  shared_ptr<SandNode> node2 = make_shared<SandNode>();
  shared_ptr<SandNode> node3 = make_shared<SandNode>();
  set<shared_ptr<SandNode>> node_set;
  SandPileFixture() {
    node_set.insert(node0);
    node_set.insert(node1);
    node_set.insert(node2);
  }
  ~SandPileFixture() {
  }
};

BOOST_AUTO_TEST_SUITE(sandpile_suite)

BOOST_AUTO_TEST_CASE(default_constructor_test) {
  SandPile test_pile;
  BOOST_CHECK_EQUAL(test_pile.get_size(), 0);
}

BOOST_AUTO_TEST_CASE(iterable_constructor_test) {
  SandPileFixture pile_fix;
  SandPile test_pile {pile_fix.node_set};
  BOOST_CHECK_EQUAL(test_pile.get_size(), pile_fix.node_set.size());
}

BOOST_AUTO_TEST_CASE(length_constructor_test) {
  int test_size = 3;
  SandPile test_pile {test_size};
  BOOST_CHECK_EQUAL(test_pile.get_size(), test_size);
}

BOOST_AUTO_TEST_CASE(iterate_nodes_test) {
  SandPileFixture pile_fix;
  SandPile test_pile {pile_fix.node_set};
  int size = 0;
  for (auto node_ : test_pile) {
    ++size;
  }
  BOOST_CHECK_EQUAL(size, test_pile.get_size());
}

BOOST_AUTO_TEST_CASE(iterate_test) {
  SandPileFixture pile_fix;
  SandPile test_pile {pile_fix.node_set};
  shared_ptr<SandNode> test_node{make_shared<SandNode>()};
  for (auto node : pile_fix.node_set) {
    test_node->add_neighbor(node);
  }
  BOOST_CHECK_EQUAL(test_node->get_value(), 0);
  BOOST_CHECK_EQUAL(test_node->get_rank(), pile_fix.node_set.size());
  test_pile.add_node(test_node);
  BOOST_CHECK_EQUAL(test_pile.iterate(), 0);
  for (int i=0; i < pile_fix.node_set.size(); ++i) {
    test_node->increment_value();
  }
  BOOST_CHECK_EQUAL(test_pile.iterate(), 1);
}

BOOST_AUTO_TEST_CASE(set_max_test) {
  SandPileFixture pile_fix;
  SandPile test_pile {pile_fix.node_set};
  shared_ptr<SandNode> test_node1{make_shared<SandNode>()};
  shared_ptr<SandNode> test_node2{make_shared<SandNode>()};
  for (auto node : pile_fix.node_set) {
    test_node1->add_neighbor(node, true);
    test_node2->add_neighbor(node, true);
  }
  test_pile.set_max();
  for (auto node_ : test_pile) {
    BOOST_CHECK_EQUAL(node_->get_value(), 1);
  }
}

BOOST_AUTO_TEST_SUITE_END()
