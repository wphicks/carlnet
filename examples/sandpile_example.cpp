#include <fstream>
#include "sandpile.hpp"
#include "linking.hpp"

int main() {
  constexpr int width = 10;
  constexpr int height = 10;
  constexpr int iterations = 10000;

  // Create sandpile on grid
  SandPile my_pile {width*height};
  sink_grid_connect(my_pile, width, height);
  my_pile.set_max();

  // Create file to store data
  std::ofstream datafile;
  datafile.open("sandpile.data", std::ofstream::app);

  // Run simulation
  for (int i=0; i < iterations; ++i) {
    datafile << my_pile.iterate() << ", ";
  }

  // Cleanup
  datafile.close();
  return 0;
}
