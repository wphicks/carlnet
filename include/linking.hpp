#ifndef INCLUDE_LINKING_HPP_
#define INCLUDE_LINKING_HPP_
template <class Graph>
void grid_connect(Graph node_set, int width, int height) {
  /*! \brief Connect nodes in an ordinary 2D grid
   */
  // TODO: Link to sink node
  auto start_node = node_set.begin();
  for (int i=0; i < height; ++i) {
    for (int j=0; j < width; ++j) {
      (*(start_node + i*width + j))->add_neighbor(
        *(start_node + i*width + ((j + 1) % width))
      );
      (*(start_node + i*width + j))->add_neighbor(
        *(start_node + ((i + 1) % height)*width + j)
      );
    }
  }
}
#endif  // INCLUDE_LINKING_HPP_
