#include "pq.hpp"   // The header file for our custom linked list class
#include <cstddef>  // Include to use NULL, otherwise use nullptr
#include <fstream>  // Include to open files
#include <iostream> // Include to print to the screen
using namespace std;

int main(int argc, char **argv) {
  PQ<int> pq;
  Node<int> *searchResult;
  std::ifstream input;
  int cmd, argument, ret, prio;

  if (argc < 2) {
    std::cout << "useage: ./pq.out <cmd file>\n";
    return 0;
  }

  input.open(argv[1]);

  // while there is something to read from the file, read
  while (input >> cmd) {
    // switch on the command we read from the file
    switch (cmd) {
      // if the cmd requires a parameter, read it from the file and call the
      // associated function
    case 1:
      input >> argument;
      input >> prio;
      pq.enqueue(argument, prio);
      std::cout << "enqueu " << argument << " priority " << prio << endl;
      break;
    case 2:
      pq.dequeue();
      break;
    case 3:
      ret = pq.get_front();
      std::cout << "Front: " << ret << endl;
      break;
    case 4:
      if (pq.isEmpty())
        std::cout << "queue is empty\n";
      else
        std::cout << "queue is not empty\n";
      break;
    case 5:
      pq.clear();
      break;
    case 6:
      ret = pq.get_count();
      std::cout << "queue has " << ret << "elements\n";
    }
  }
  input.close();

  return 0;
}
