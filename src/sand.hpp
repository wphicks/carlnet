#include "node.hpp"

class SandNode : public CellNode {
  /*! \brief A node in a sandpile model
   */
 public:
    SandNode();
    template <template <typename...> class Iterable>
    explicit SandNode(const Iterable<SandNode*> &all_neighbors) :
        CellNode(all_neighbors) {
    }
    int get_grains();
    /*! \brief Return number of grains on this node
     */
    void add_grain();
    /*! \brief Add a grain to this node
     */
    bool iterate();
    /*! \brief Iterate sandpile dynamics for this node
     */
 private:
    int grains;
     /*! \brief The number of "grains" on this node
      */
};
