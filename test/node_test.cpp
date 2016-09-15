#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE linked_list_test
#include <set>
#include <boost/test/included/unit_test.hpp>
#include "node.hpp"

using std::set;

struct CellNodeFixture {
  CellNode * node0;
  CellNode * node1;
  CellNode * node2;
  CellNode * node3;
  set<CellNode*> node_set;
  CellNodeFixture() {
    node0 = new CellNode;
    node1 = new CellNode;
    node2 = new CellNode;
    node3 = new CellNode;
    node_set.insert(node0);
    node_set.insert(node1);
    node_set.insert(node2);
  }
  ~CellNodeFixture() {
    delete node0;
    delete node1;
    delete node2;
    delete node3;
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

BOOST_AUTO_TEST_CASE(remove_neighbor_test) {
  CellNodeFixture node_fix;
  CellNode test_node {node_fix.node_set};
  BOOST_CHECK(test_node.has_neighbor(node_fix.node0));
  test_node.remove_neighbor(node_fix.node0);
  BOOST_CHECK(!test_node.has_neighbor(node_fix.node0));
}

BOOST_AUTO_TEST_CASE(iteration_test) {
  CellNode test_node;
  BOOST_CHECK(!test_node.iterate());
}

BOOST_AUTO_TEST_SUITE_END()

