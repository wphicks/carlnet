#ifndef INCLUDE_VALUE_NODE_HPP_
#define INCLUDE_VALUE_NODE_HPP_
#include<memory>
#include "node.hpp"
using std::shared_ptr;

class ValueNode : public Node {
  /*! \brief A node in a sandpile model
   */
 public:
    ValueNode();
    template <typename Iterator>
    ValueNode(Iterator first, Iterator end) :
        Node{first, end} {
    }
    ~ValueNode();
    int get_value();
    /*! \brief Return value assigned to this node
     */
    bool increment_value();
    /*! \brief Increase value of this node by one
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
#endif  // INCLUDE_VALUE_NODE_HPP_
