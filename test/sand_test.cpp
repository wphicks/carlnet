#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE sand_test
#include <set>
#include <memory>
#include <boost/test/included/unit_test.hpp>
#include "sand.hpp"

using std::set;
using std::shared_ptr;
using std::make_shared;

struct SandNodeFixture {
  shared_ptr<SandNode> node0 = make_shared<SandNode>();
  shared_ptr<SandNode> node1 = make_shared<SandNode>();
  shared_ptr<SandNode> node2 = make_shared<SandNode>();
  shared_ptr<SandNode> node3 = make_shared<SandNode>();
  set<shared_ptr<SandNode>> node_set;
  SandNodeFixture() {
    node_set.insert(node0);
    node_set.insert(node1);
    node_set.insert(node2);
  }
  ~SandNodeFixture() {
  }
};

BOOST_AUTO_TEST_SUITE(sand_suite)

BOOST_AUTO_TEST_CASE(default_constructor_test) {
  SandNode test_node;
  BOOST_CHECK_EQUAL(test_node.get_value(), 0);
}

BOOST_AUTO_TEST_CASE(add_grain_test) {
  SandNodeFixture node_fix;
  SandNode test_node {node_fix.node_set.begin(), node_fix.node_set.end()};
  BOOST_CHECK_EQUAL(test_node.get_value(), 0);
  test_node.increment_value();
  BOOST_CHECK_EQUAL(test_node.get_value(), 1);
}

BOOST_AUTO_TEST_CASE(add_neighbor_test) {
  SandNodeFixture node_fix;
  SandNode test_node {node_fix.node_set.begin(), node_fix.node_set.end()};
  BOOST_CHECK(!test_node.has_neighbor(node_fix.node3));
  test_node.add_neighbor(node_fix.node3);
  BOOST_CHECK(test_node.has_neighbor(node_fix.node3));
}

BOOST_AUTO_TEST_CASE(iterate_test) {
  SandNodeFixture node_fix;
  SandNode test_node {node_fix.node_set.begin(), node_fix.node_set.end()};
  BOOST_CHECK(!test_node.iterate());
  for (int i=0; i < node_fix.node_set.size(); ++i) {
    test_node.increment_value();
  }
  for (auto node_iter : node_fix.node_set) {
    BOOST_CHECK_EQUAL(node_iter->get_value(), 0);
  }
  BOOST_CHECK(test_node.iterate());
  BOOST_CHECK_EQUAL(test_node.get_value(), 0);
  for (auto node_iter : node_fix.node_set) {
    BOOST_CHECK_EQUAL(node_iter->get_value(), 1);
  }
}

BOOST_AUTO_TEST_CASE(set_max_test) {
  SandNodeFixture node_fix;
  SandNode test_node {node_fix.node_set.begin(), node_fix.node_set.end()};
  test_node.set_max();
  BOOST_CHECK_EQUAL(test_node.get_value(), node_fix.node_set.size()-1);
}

BOOST_AUTO_TEST_SUITE_END()


