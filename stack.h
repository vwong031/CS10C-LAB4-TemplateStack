#include <iostream>
using namespace std;

#ifndef STACK_H
#define STACK_H

const int MAX_SIZE = 20;

template <typename T>
class stack {
  private:
    T data[MAX_SIZE];
    int size;
  public:
    stack();
    /* constructs an empty stack */
    void push(T val);
    /* inserts a new element (val) of type T into the data. If the data 
    array is full, this fct should throw an overflow_error exception with 
    error msg: "Called push on full stack." */ 
    void pop(); 
    /* removes the last element from data. If the data array is empty, this
    fct should throw an outofrange exception w/ error msg: "Called pop on 
    empty stack." */
    T top();
    /* returns the top element of stack. If stack is empty, this fct should
    throw an underflow_error exception w/ error msg: "Called top on empty
    stack." */
    bool empty();
    /* returns true if the stack is empty otherwise it returns false */
};

template<typename T>
stack<T>::stack() {
  size = 0;
}

template<typename T>
void stack<T>::push(T val) {
  // if there is no more space in the array, throw error
  if (size == MAX_SIZE) {
    throw overflow_error("Called push on full stack.");
  }

  // insert val into the array at index "size"
  data[size] = val; 
  // increase count of elements in array
  ++size;
}

template<typename T>
void stack<T>::pop() {
  // if array is empty, throw an error
  if (size == 0) {
    throw out_of_range("Called pop on empty stack.");
  }
  
  // decrease the size, which pops the last element
  size -= 1; 
} 

template<typename T>
T stack<T>::top() {
  // if array is empty, throw error
  if (size == 0) {
    throw underflow_error("Called top on empty stack.");
  }

  // else return the top element
  return data[size - 1];
}

template<typename T>
bool stack<T>::empty() {
  if (size == 0) {
    return true;
  }
  else {
    return false; 
  }
}

#endif
