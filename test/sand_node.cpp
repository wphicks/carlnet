#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE sand_node_test

struct SandNodeFixture {
  SandNodeFixture() {
  }
  ~SandNodeFixture() {
  }
};

BOOST_AUTO_TEST_SUITE(sand_node_test)

BOOST_AUTO_TEST_CASE(increment_value_test) {
  SandNodeFixture node_fix;
  SandNode test_node {node_fix.node_set.begin(), node_fix.node_set.end()};
  BOOST_CHECK_EQUAL(test_node.get_value(), 0);
  test_node.increment_value();
  BOOST_CHECK_EQUAL(test_node.get_value(), 1);
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
