#ifndef INCLUDE_NODE_HPP_
#define INCLUDE_NODE_HPP_
#include <set>
#include <memory>
#include <stdexcept>
using std::set;
using std::shared_ptr;
using std::weak_ptr;
using std::owner_less;
using std::logic_error;
using std::static_pointer_cast;
using std::enable_shared_from_this;

class CellNode : public enable_shared_from_this<CellNode> {
    /*! \brief A node in a directed graph of automata
     */
 public:
    CellNode();
    template <template <typename...> class Iterable>
    explicit CellNode(const Iterable<shared_ptr<CellNode>> &all_neighbors) {
      for (
          auto neighbor_iter = all_neighbors.begin();
          neighbor_iter != all_neighbors.end();
          ++neighbor_iter) {
        add_neighbor(*neighbor_iter);
      }
    }
    virtual ~CellNode();
    int get_rank();
    /*! \brief Return the number of neighbors for this node
     */
    void add_neighbor(shared_ptr<CellNode> new_neighbor, bool mutual);
    /*! \brief Add neighbor to node
     *
     * \param new_neighbor: the neighbor to add
     * \param mutual: also make this node a neighbor of the added node
     */
    void add_neighbor(shared_ptr<CellNode> new_neighbor);
    template <class NodeType>
    void add_neighbor(shared_ptr<NodeType> new_neighbor) {
    /*! \brief Add neighbor to node
     *
     * \throw If the provided pointer cannot be cast to a shared_ptr<CellNode>,
     * this method will throw a logic_error.
     */
      shared_ptr<CellNode> cell_neighbor =
        static_pointer_cast<CellNode>(new_neighbor);
      if (cell_neighbor) {
        add_neighbor(cell_neighbor);
      } else {
        throw logic_error("New neighbor could not be cast to shared_ptr<CellNode>");
      }
    }
    void remove_neighbor(shared_ptr<CellNode> old_neighbor, bool mutual);
    /*! \brief Remove neighbor from node
     *
     * \param old_neighbor: the neighbor to remove
     * \param mutual: also remove this node as a neighbor of the added node (if
     * it is currently a neighbor)
     */
    void remove_neighbor(shared_ptr<CellNode> old_neighbor);
    bool has_neighbor(shared_ptr<CellNode> test_neighbor);
    /*! \brief Check to see if given node is a neighbor
     */
    virtual int get_value();
    /*! \brief Return value associated with this node
     */
    virtual bool increment_value();
    /*! \brief Increment value associated with this node
     *
     * \return bool indicating whether value was successfully incremented
     */
    virtual bool iterate();
    /*! \brief Perform the next iteration of the cell's lifecycle
     *
     * \return bool indicating whether a node "fired" on this iteration
     */

 protected:
    set<weak_ptr<CellNode>, owner_less<weak_ptr<CellNode>>> neighbors;
    /*! \brief A list of pointers to the neighbors of this node
     */

 private:
    int rank;
    /*! \brief The number of neighbors of this node
     */
};
#endif  // INCLUDE_NODE_HPP_
