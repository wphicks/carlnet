#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE linked_list_test
#include <set>
#include <boost/test/included/unit_test.hpp>
#include "sand.hpp"

using std::set;

struct SandNodeFixture {
  SandNode * node0;
  SandNode * node1;
  SandNode * node2;
  SandNode * node3;
  set<CellNode*> node_set;
  SandNodeFixture() {
    node0 = new SandNode;
    node1 = new SandNode;
    node2 = new SandNode;
    node3 = new SandNode;
    node_set.insert(node0);
    node_set.insert(node1);
    node_set.insert(node2);
  }
  ~SandNodeFixture() {
    delete node0;
    delete node1;
    delete node2;
    delete node3;
  }
};

BOOST_AUTO_TEST_SUITE(sand_suite)

BOOST_AUTO_TEST_CASE(default_constructor_test) {
  SandNode test_node;
  BOOST_CHECK_EQUAL(test_node.get_grains(), 0);
}

BOOST_AUTO_TEST_CASE(add_grain_test) {
  SandNodeFixture node_fix;
  SandNode test_node {node_fix.node_set};
  BOOST_CHECK_EQUAL(test_node.get_grains(), 0);
  test_node.add_grain();
  BOOST_CHECK_EQUAL(test_node.get_grains(), 1);
}

BOOST_AUTO_TEST_CASE(iterate_test) {
  SandNodeFixture node_fix;
  SandNode test_node {node_fix.node_set};
  BOOST_CHECK(!test_node.iterate());
  for (int i=0; i < node_fix.node_set.size(); ++i) {
    test_node.add_grain();
  }
  BOOST_CHECK(test_node.iterate());
  BOOST_CHECK_EQUAL(test_node.get_grains(), 0);
  for (auto node_iter : node_fix.node_set) {
    BOOST_CHECK_EQUAL(node_iter->get_grains(), 1);
  }
}

BOOST_AUTO_TEST_SUITE_END()


