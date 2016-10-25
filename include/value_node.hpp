#ifndef INCLUDE_VALUE_NODE_HPP_
#define INCLUDE_VALUE_NODE_HPP_
#include<memory>
#include "node.hpp"
using std::shared_ptr;

template<typename ValueType>
class ValueNode : public Node {
  /*! \brief A node labeled with a "value" of any type
   */
 public:
    ValueNode() : Node{}, value{} {
    };
    template <typename Iterator>
    ValueNode(Iterator first, Iterator end) :
        Node{first, end}, value{} {
    }
    ~ValueNode() {
    }
    ValueType get_value() {
    /*! \brief Return value assigned to this node
     */
      return value;
    }
 protected:
    ValueType value;
     /*! \brief The value assigned to this node
      */
};

typedef ValueNode<int> IntNode;
/*! \brief A node with an integer value
 */
typedef ValueNode<double> DoubleNode;
/*! \brief A node with a double value
 */
#endif  // INCLUDE_VALUE_NODE_HPP_
