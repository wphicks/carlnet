#ifndef INCLUDE_SANDPILE_HPP_
#define INCLUDE_SANDPILE_HPP_

#include <vector>
#include "value_node.hpp"
#include "node.hpp"
using std::make_shared;
using std::vector;
using std::iterator;

class SandPile {
 public:
    SandPile();
    template <typename Iterator>
    SandPile(Iterator first, Iterator end) :
        SandPile{} {
      for (
          auto node_iter = first;
          node_iter != end;
          ++node_iter) {
        add_node(*node_iter);
      }
    }
    explicit SandPile(int num_nodes);
    /*! \brief Create sandpile with given number of nodes (excluding sink node)
     */
    int get_size();
    /*! \brief Return the number of nodes in this sandpile
     */
    void add_node(shared_ptr<ValueNode> new_node);
    /*! \brief Add node to sandpile model
     */
    int iterate();
    /*! \brief Iterate sandpile dynamics forward one timestep
     *
     * \return The number of nodes that "avalanched"
     */
    vector<shared_ptr<ValueNode>>::const_iterator begin();
    /*! \brief Return iterator to first node in pile
     */
    vector<shared_ptr<ValueNode>>::const_iterator end();
    /*! \brief Return iterator to end of pile
     */
    void set_max();
    /*! \brief Set all nodes to maximum stable value
     */
    const shared_ptr<Node> get_sink();
    /*! \brief Return pointer to sink node
     */

 protected:
    vector<shared_ptr<ValueNode>> nodes;
    shared_ptr<Node> sink;
    /*! \brief A node which will never avalanche
     *
     */
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
