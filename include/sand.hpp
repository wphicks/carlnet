#include "node.hpp"

class SandNode : public CellNode {
  /*! \brief A node in a sandpile model
   */
 public:
    SandNode();
    template <template <typename...> class Iterable>
    explicit SandNode(const Iterable<CellNode*> &all_neighbors) :
        CellNode(all_neighbors) {
    }
    ~SandNode();
    int get_value();
    /*! \brief Return number of grains on this node
     */
    bool increment_value();
    /*! \brief Add a grain to this node
     */
    bool iterate();
    /*! \brief Iterate sandpile dynamics for this node
     */
 private:
    int value;
     /*! \brief The number of "grains" on this node
      */
};
