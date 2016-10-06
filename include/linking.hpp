#ifndef INCLUDE_LINKING_HPP_
#define INCLUDE_LINKING_HPP_
template <class Graph>
void periodic_grid_connect(Graph node_set, int width, int height) {
  /*! \brief Connect nodes in a periodic 2D grid
   */
  auto start_node = node_set.begin();
  for (int i=0; i < height; ++i) {
    for (int j=0; j < width; ++j) {
      (*(start_node + i*width + j))->add_neighbor(
        *(start_node + i*width + ((j + 1) % width)),
        true
      );
      (*(start_node + i*width + j))->add_neighbor(
        *(start_node + ((i + 1) % height)*width + j),
        true
      );
    }
  }
}

template <class Graph>
void grid_connect(Graph node_set, int width, int height) {
  /*! \brief Connect nodes in a non-periodic grid with edges connected to sink
   * node
   */
  auto start_node = node_set.begin();
  for (int i=0; i < height; ++i) {
    for (int j=0; j < width; ++j) {
      if (i == 0 || j == 0) {
        (*(start_node + i*width + j))->add_neighbor(*start_node);
      }
      if (j == width - 1) {
        (*(start_node + i*width + j))->add_neighbor(*start_node);
      } else {
        (*(start_node + i*width + j))->add_neighbor(
          *(start_node + i*width + ((j + 1) % width)),
          true
        );
      }
      if (i == height - 1) {
        (*(start_node + i*width + j))->add_neighbor(*start_node);
      } else {
        (*(start_node + i*width + j))->add_neighbor(
          *(start_node + ((i + 1) % height)*width + j),
          true
        );
      }
    }
  }
}
#endif  // INCLUDE_LINKING_HPP_
