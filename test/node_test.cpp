#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE node_test
#include <set>
#include <memory>
#include <boost/test/included/unit_test.hpp>
#include "node.hpp"

using std::set;
using std::shared_ptr;
using std::make_shared;

struct CellNodeFixture {
  shared_ptr<CellNode> node0 = make_shared<CellNode>();
  shared_ptr<CellNode> node1 = make_shared<CellNode>();
  shared_ptr<CellNode> node2 = make_shared<CellNode>();
  shared_ptr<CellNode> node3 = make_shared<CellNode>();
  set<shared_ptr<CellNode>> node_set;
  CellNodeFixture() {
    node_set.insert(node0);
    node_set.insert(node1);
    node_set.insert(node2);
  }
  ~CellNodeFixture() {
  }
};

BOOST_AUTO_TEST_SUITE(node_suite)

BOOST_AUTO_TEST_CASE(default_constructor_test) {
  CellNode test_node;
  BOOST_CHECK_EQUAL(test_node.get_rank(), 0);
  BOOST_CHECK_EQUAL(test_node.get_value(), 0);
}

BOOST_AUTO_TEST_CASE(iterable_constructor_test) {
  CellNodeFixture node_fix;
  CellNode test_node {node_fix.node_set};
  BOOST_CHECK_EQUAL(test_node.get_rank(), 3);
}

BOOST_AUTO_TEST_CASE(has_neighbor_test) {
  CellNodeFixture node_fix;
  CellNode test_node {node_fix.node_set};
  BOOST_CHECK(test_node.has_neighbor(node_fix.node0));
}

BOOST_AUTO_TEST_CASE(add_neighbor_test) {
  CellNodeFixture node_fix;
  CellNode test_node {node_fix.node_set};
  BOOST_CHECK(!test_node.has_neighbor(node_fix.node3));
  test_node.add_neighbor(node_fix.node3);
  BOOST_CHECK(test_node.has_neighbor(node_fix.node3));
}

BOOST_AUTO_TEST_CASE(add_neighbor_mutual_test) {
  CellNodeFixture node_fix;
  shared_ptr<CellNode> test_node = make_shared<CellNode>(node_fix.node_set);
  BOOST_CHECK(!test_node->has_neighbor(node_fix.node3));
  BOOST_CHECK(!node_fix.node3->has_neighbor(test_node));
  test_node->add_neighbor(node_fix.node3, true);
  BOOST_CHECK(test_node->has_neighbor(node_fix.node3));
  BOOST_CHECK(node_fix.node3->has_neighbor(test_node));
}

BOOST_AUTO_TEST_CASE(remove_neighbor_test) {
  CellNodeFixture node_fix;
  shared_ptr<CellNode> test_node = make_shared<CellNode>();
  test_node->add_neighbor(node_fix.node0, true);
  BOOST_CHECK(test_node->has_neighbor(node_fix.node0));
  BOOST_CHECK(node_fix.node0->has_neighbor(test_node));
  test_node->remove_neighbor(node_fix.node0, true);
  BOOST_CHECK(!test_node->has_neighbor(node_fix.node0));
  BOOST_CHECK(!node_fix.node0->has_neighbor(test_node));
}

BOOST_AUTO_TEST_CASE(iteration_test) {
  CellNode test_node;
  BOOST_CHECK(!test_node.iterate());
}

BOOST_AUTO_TEST_SUITE_END()

