#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data;
  int m_ary;
  PComparator comp;

};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
  m_ary = m;
  comp = c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  return data.empty();
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return data.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
    data.push_back(item);
    std::size_t index = data.size() - 1;
    while (index != 0) {
        std::size_t parent_index = (index - 1) / m_ary;
        T& current = data[index];
        T& parent = data[parent_index];
        if (!comp(current, parent)) {
            break;
        }
        std::swap(current, parent);
        index = parent_index;
    }
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::out_of_range("heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap

template <typename T, typename PComparator>
void Heap<T,PComparator>::pop() {
    if (empty()) {
        throw std::out_of_range("heap is empty");
    }

    // TO BE COMPLETETED
    data[0] = data[size()-1];
    data.pop_back();
    //data.size() = data.size()-1;
    if (data.empty()) return;

    int index = 0;
    while (true){
        //size_t left = 2 * index + 1;
        //size_t right = 2 * index + 2;
        int best_child = index; // Assume left is smaller initially

        for (int i = 1; i <= m_ary; i++){
          int child = m_ary * index + i;
          if (child < data.size()) {
            if (comp(data[child], data[best_child])){
              best_child = child;
            }
          }
        }
        // If right child exists and is smaller than left child, select right child
        

        // If current element is smaller or equal to the largest child, heap property holds
        if (best_child == index) {
            break;
        }

        // Swap with the larger child and continue down
        std::swap(data[index], data[best_child]);
        index = best_child;
    }
  }


#endif

