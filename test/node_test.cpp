#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE node_test
#include <set>
#include <memory>
#include <boost/test/included/unit_test.hpp>
#include "node.hpp"

using std::set;
using std::shared_ptr;
using std::make_shared;

struct NodeFixture {
  shared_ptr<Node> node0 = make_shared<Node>();
  shared_ptr<Node> node1 = make_shared<Node>();
  shared_ptr<Node> node2 = make_shared<Node>();
  shared_ptr<Node> node3 = make_shared<Node>();
  set<shared_ptr<Node>> node_set;
  NodeFixture() {
    node_set.insert(node0);
    node_set.insert(node1);
    node_set.insert(node2);
  }
  ~NodeFixture() {
  }
};

BOOST_AUTO_TEST_SUITE(node_suite)

BOOST_AUTO_TEST_CASE(default_constructor_test) {
  Node test_node;
  BOOST_CHECK_EQUAL(test_node.get_rank(), 0);
}

BOOST_AUTO_TEST_CASE(iterable_constructor_test) {
  NodeFixture node_fix;
  Node test_node {node_fix.node_set.begin(), node_fix.node_set.end()};
  BOOST_CHECK_EQUAL(test_node.get_rank(), 3);
}

BOOST_AUTO_TEST_CASE(has_neighbor_test) {
  NodeFixture node_fix;
  Node test_node {node_fix.node_set.begin(), node_fix.node_set.end()};
  BOOST_CHECK(test_node.has_neighbor(node_fix.node0));
}

BOOST_AUTO_TEST_CASE(add_neighbor_test) {
  NodeFixture node_fix;
  Node test_node {node_fix.node_set.begin(), node_fix.node_set.end()};
  BOOST_CHECK(!test_node.has_neighbor(node_fix.node3));
  test_node.add_neighbor(node_fix.node3);
  BOOST_CHECK(test_node.has_neighbor(node_fix.node3));
}

BOOST_AUTO_TEST_CASE(add_neighbor_mutual_test) {
  NodeFixture node_fix;
  shared_ptr<Node> test_node = make_shared<Node>(
      node_fix.node_set.begin(), node_fix.node_set.end());
  BOOST_CHECK(!test_node->has_neighbor(node_fix.node3));
  BOOST_CHECK(!node_fix.node3->has_neighbor(test_node));
  test_node->add_neighbor(node_fix.node3, true);
  BOOST_CHECK(test_node->has_neighbor(node_fix.node3));
  BOOST_CHECK(node_fix.node3->has_neighbor(test_node));
}

BOOST_AUTO_TEST_CASE(remove_neighbor_test) {
  NodeFixture node_fix;
  shared_ptr<Node> test_node = make_shared<Node>();
  test_node->add_neighbor(node_fix.node0, true);
  BOOST_CHECK(test_node->has_neighbor(node_fix.node0));
  BOOST_CHECK(node_fix.node0->has_neighbor(test_node));
  test_node->remove_neighbor(node_fix.node0, true);
  BOOST_CHECK(!test_node->has_neighbor(node_fix.node0));
  BOOST_CHECK(!node_fix.node0->has_neighbor(test_node));
}

BOOST_AUTO_TEST_CASE(iteration_test) {
  Node test_node;
  BOOST_CHECK(!test_node.iterate());
}

BOOST_AUTO_TEST_SUITE_END()

