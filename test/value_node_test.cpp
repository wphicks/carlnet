#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE value_node_test
#include <set>
#include <memory>
#include <boost/test/included/unit_test.hpp>
#include "value_node.hpp"

using std::set;
using std::shared_ptr;
using std::make_shared;

struct ValueNodeFixture {
  shared_ptr<ValueNode> node0 = make_shared<ValueNode>();
  shared_ptr<ValueNode> node1 = make_shared<ValueNode>();
  shared_ptr<ValueNode> node2 = make_shared<ValueNode>();
  shared_ptr<ValueNode> node3 = make_shared<ValueNode>();
  set<shared_ptr<ValueNode>> node_set;
  ValueNodeFixture() {
    node_set.insert(node0);
    node_set.insert(node1);
    node_set.insert(node2);
  }
  ~ValueNodeFixture() {
  }
};

BOOST_AUTO_TEST_SUITE(value_node_suite)

BOOST_AUTO_TEST_CASE(default_constructor_test) {
  ValueNode test_node;
  BOOST_CHECK_EQUAL(test_node.get_value(), 0);
}

BOOST_AUTO_TEST_CASE(add_neighbor_test) {
  ValueNodeFixture node_fix;
  ValueNode test_node {node_fix.node_set.begin(), node_fix.node_set.end()};
  BOOST_CHECK(!test_node.has_neighbor(node_fix.node3));
  test_node.add_neighbor(node_fix.node3);
  BOOST_CHECK(test_node.has_neighbor(node_fix.node3));
}

BOOST_AUTO_TEST_SUITE_END()
