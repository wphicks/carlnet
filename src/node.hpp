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
    // virtual bool iterate();
    /*! \brief Perform the next iteration of the cell's lifecycle
     */
 private:
    set<CellNode*> neighbors;
    /*! \brief A list of pointers to the neighbors of this node
     */
    int rank;
    /*! \brief The number of neighbors of this node
     */
};