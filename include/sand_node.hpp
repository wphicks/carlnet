#ifndef INCLUDE_SAND_NODE_HPP_
#define INCLUDE_SAND_NODE_HPP_
#include "value_node.hpp"
class SandNode : public ValueNode {
  /*! \brief A node in a sandpile model
   */
 public:
    SandNode();
    template <typename Iterator>
    SandNode(Iterator first, Iterator end) :
        ValueNode{first, end} {
    }
    ~SandNode();
    void increment_value();
    /*! \brief Increase value of this node by one
     */
    bool iterate();
    /*! \brief Iterate sandpile dynamics for this node
     */
    void set_max();
    /*! \brief Set value to maximum without avalanching
     */
};
#endif  // INCLUDE_SAND_NODE_HPP_
