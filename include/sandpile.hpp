#ifndef INCLUDE_SANDPILE_HPP_
#define INCLUDE_SANDPILE_HPP_

#include <vector>
#include "sand.hpp"
using std::vector;

class SandPile {
 public:
    SandPile();
    template <template <typename...> class Iterable>
    explicit SandPile(const Iterable<shared_ptr<SandNode>> &all_nodes) {
      for (
          auto node_iter = all_nodes.begin();
          node_iter != all_nodes.end();
          ++node_iter) {
        add_node(*node_iter);
      }
    }
    explicit SandPile(int num_nodes);
    int get_size();
    /*! \brief Return the number of nodes in this sandpile
     */
    void add_node(shared_ptr<SandNode> new_node);
    /*! \brief Add node to sandpile model
     */
    int iterate();
    /*! \brief Iterate sandpile dynamics forward one timestep
     *
     * \return The number of nodes that "avalanched"
     */

 protected:
    vector<shared_ptr<SandNode>> nodes;

 private:
    int size;
};

#endif  // INCLUDE_SANDPILE_HPP_
