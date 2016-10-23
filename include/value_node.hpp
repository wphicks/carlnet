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
 protected:
    int value;
     /*! \brief The value assigned to this node
      */
};
#endif  // INCLUDE_VALUE_NODE_HPP_
