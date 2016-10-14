#ifndef INCLUDE_SAND_HPP_
#define INCLUDE_SAND_HPP_
#include<memory>
#include "node.hpp"
using std::shared_ptr;

class SandNode : public Node {
  /*! \brief A node in a sandpile model
   */
 public:
    SandNode();
    template <template <typename...> class Iterable>
    explicit SandNode(const Iterable<shared_ptr<Node>> &all_neighbors) :
        Node(all_neighbors) {
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
    void set_max();
    /*! \brief Set value to maximum without avalanching
     */
 private:
    int value;
     /*! \brief The number of "grains" on this node
      */
};
#endif  // INCLUDE_SAND_HPP_
