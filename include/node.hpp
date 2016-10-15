#ifndef INCLUDE_NODE_HPP_
#define INCLUDE_NODE_HPP_
#include <vector>
#include <memory>
#include <stdexcept>
using std::vector;
using std::shared_ptr;
using std::weak_ptr;
using std::owner_less;
using std::logic_error;
using std::static_pointer_cast;
using std::enable_shared_from_this;

class Node : public enable_shared_from_this<Node> {
    /*! \brief A node in a directed graph of agents
     */
 public:
    Node();
    template <typename Iterator>
    Node(Iterator first, Iterator end) {
      /*! \brief Construct node from iterable of shared_ptrs
       *
       * \param first: Iterator to first shared_ptr in container
       * \param end: Iterator to end of container
       */
      for (
          auto neighbor_iter = first;
          neighbor_iter != end;
          ++neighbor_iter) {
        add_neighbor(*neighbor_iter);
      }
    }
    virtual ~Node();
    int get_rank();
    /*! \brief Return the number of neighbors for this node
     */
    void add_neighbor(shared_ptr<Node> new_neighbor, bool mutual);
    /*! \brief Add neighbor to node
     *
     * \param new_neighbor: the neighbor to add
     * \param mutual: also make this node a neighbor of the added node
     */
    void add_neighbor(shared_ptr<Node> new_neighbor);
    template <class NodeType>
    void add_neighbor(shared_ptr<NodeType> new_neighbor) {
    /*! \brief Add neighbor to node
     *
     * \throw If the provided pointer cannot be cast to a shared_ptr<Node>,
     * this method will throw a logic_error.
     */
      shared_ptr<Node> cell_neighbor =
        static_pointer_cast<Node>(new_neighbor);
      if (cell_neighbor) {
        add_neighbor(cell_neighbor);
      } else {
        throw logic_error("New neighbor could not be cast to shared_ptr<Node>");
      }
    }
    void remove_neighbor(shared_ptr<Node> old_neighbor, bool mutual);
    /*! \brief Remove neighbor from node
     *
     * \param old_neighbor: the neighbor to remove
     * \param mutual: also remove this node as a neighbor of the added node (if
     * it is currently a neighbor)
     */
    void remove_neighbor(shared_ptr<Node> old_neighbor);
    bool has_neighbor(shared_ptr<Node> test_neighbor);
    /*! \brief Check to see if given node is a neighbor
     */
    virtual bool iterate();
    /*! \brief Perform the next iteration of the cell's lifecycle
     *
     * \return bool indicating whether a node "fired" on this iteration
     */

 protected:
    vector<weak_ptr<Node>> neighbors;
    /*! \brief A list of pointers to the neighbors of this node
     */

 private:
    int rank;
    /*! \brief The number of neighbors of this node
     */
};
#endif  // INCLUDE_NODE_HPP_
