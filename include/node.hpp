#include <set>
using std::set;

class CellNode {
    /*! \brief A node in an undirected graph of cellular automata
     */
 public:
    CellNode();
    template <template <typename...> class Iterable>
    explicit CellNode(const Iterable<CellNode*> &all_neighbors) {
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
    void add_neighbor(CellNode* new_neighbor);
    /*! \brief Add neighbor to node
     */
    void remove_neighbor(CellNode* old_neighbor);
    /*! \brief Remove neighbor from node
     */
    bool has_neighbor(CellNode* test_neighbor);
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
    set<CellNode*> neighbors;
    /*! \brief A list of pointers to the neighbors of this node
     */

 private:
    int rank;
    /*! \brief The number of neighbors of this node
     */
};
