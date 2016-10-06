#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE sandpile_test
#include <memory>
#include <vector>
#include <boost/test/included/unit_test.hpp>
#include "sand.hpp"
#include "sandpile.hpp"
#include "linking.hpp"

using std::set;
using std::make_shared;

struct LinkingFixture {
  static constexpr int pile_size = 9;
  static constexpr int pile_width = 3;
  static constexpr int pile_height = pile_size/pile_width;
  SandPile test_pile {pile_size};
  vector<shared_ptr<SandNode>> nodes;
  LinkingFixture() {
    for (auto node_ : test_pile){
      nodes.push_back(node_);
    }
  }
};

BOOST_AUTO_TEST_SUITE(linking_suite)

BOOST_AUTO_TEST_CASE(periodic_grid_connect_test) {
  LinkingFixture link_fix;
  periodic_grid_connect(link_fix.test_pile, link_fix.pile_width, link_fix.pile_height);
  for (int i=0; i < link_fix.pile_height; ++i) {
    for (int j=0; j < link_fix.pile_width; ++j) {
      BOOST_CHECK(link_fix.nodes[
        i*link_fix.pile_width + j]->has_neighbor(
          link_fix.nodes[i*link_fix.pile_width + ((j + 1) % link_fix.pile_width)]
        )
      );
      BOOST_CHECK(link_fix.nodes[
        i*link_fix.pile_width + j]->has_neighbor(
          link_fix.nodes[((i + 1) % link_fix.pile_height)*link_fix.pile_width + j]
        )
      );
    }
  }
}
BOOST_AUTO_TEST_SUITE_END()




