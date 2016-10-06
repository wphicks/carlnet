#ifndef INCLUDE_SANDPILE_HPP_
#define INCLUDE_SANDPILE_HPP_

#include <vector>
#include "sand.hpp"
using std::make_shared;
using std::vector;
using std::iterator;

class SandPile {
 public:
    SandPile();
    template <template <typename...> class Iterable>
    explicit SandPile(const Iterable<shared_ptr<SandNode>> &all_nodes) : size{0} {
      add_node(make_shared<SandNode>());
      for (
          auto node_iter = all_nodes.begin();
          node_iter != all_nodes.end();
          ++node_iter) {
        add_node(*node_iter);
      }
    }
    explicit SandPile(int num_nodes);
    /*! \brief Create sandpile with given number of nodes (including sink node)
     */
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
    vector<shared_ptr<SandNode>>::const_iterator begin();
    /*! \brief Return iterator to first node in pile
     */
    vector<shared_ptr<SandNode>>::const_iterator end();
    /*! \brief Return iterator to end of pile
     */
    void set_max();
    /*! \brief Set all nodes to maximum stable value
     */

 protected:
    vector<shared_ptr<SandNode>> nodes;
    int iterate_without_source();
    /*! \brief Iterate sandpile dynamics without adding any grains
     *
     * \return The number of nodes that "avalanched"
     */

 private:
    int size;
    /*! \brief The number of nodes in this sandpile
     */
};

#endif  // INCLUDE_SANDPILE_HPP_
