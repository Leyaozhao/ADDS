#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <cmath> // for floor()

template <typename T>
class Heap {
 private:
  std::vector<T> values;
  void heapify(int);

 public:
  Heap();  

  Heap(std::vector<T>);

  void insert(T);
  void remove(T);
  T getMin();
};



template <typename T>
Heap<T>::Heap() {}


template <typename T>
Heap<T>::Heap(std::vector<T> start_values) {
  // copy the values into our heap vector
  for (int i = 0; i < start_values.size(); i++) {
    values.push_back(start_values.at(i));
  }

  // starting from last non-leaf node (last parent), heapify each
  // of the parents
  int initial_parent_index = floor((values.size()-1) / 2);
  for (int parent_index = initial_parent_index; parent_index >= 0;
       parent_index--) {
    heapify(parent_index);
  }
}


template <typename T>
void Heap<T>::insert(T value) {
    values.push_back(value);

    int index = values.size() - 1;
    //values[(index - 1) / 2] mean parent index
    while (index > 0 && values[(index - 1) / 2] > values[index]) {

        std::swap(values[(index - 1) / 2], values[index]);

        index = (index - 1) / 2;
        //index set to its parent index
    }
}



template <typename T>
void Heap<T>::remove(T value) {
    values[0] = values.back();
    values.pop_back();
    heapify(0);
}


template <typename T>
T Heap<T>::getMin() {
  return values.at(0);
}

/*******************************/
// private function to heapify a given 'node'
/*******************************/

template <typename T>
void Heap<T>::heapify(int parent_index) {
  // if we're outside the index range, return
  if (parent_index < 0 || parent_index >= values.size()) return;

  // find children indexes
  int left_child_index = parent_index * 2 + 1;
  int right_child_index = parent_index * 2 + 2;

  // if parent is larger than child, swap with smallest child
  int index_of_smallest = parent_index;

  // check if left child exists and if exists, is smallest value there
  if (left_child_index < values.size() &&
      values.at(left_child_index) < values.at(index_of_smallest)) {
    // make this index the current smallest
    index_of_smallest = left_child_index;
  }

  // check if left child exists and if exists, is smallest value there
  if (right_child_index < values.size() &&
      values.at(right_child_index) < values.at(index_of_smallest)) {
    // make this index the current smallest
    index_of_smallest = right_child_index;
  }

  // if parent is not smallest, swap with smallest child
  if (index_of_smallest != parent_index) {
    T temp = values.at(parent_index);
    values.at(parent_index) = values.at(index_of_smallest);
    values.at(index_of_smallest) = temp;

    // heapify the swapped index - it may need to move
    // further down the 'tree'
    heapify(index_of_smallest);
  }
}

#endif