/* -----------------------------------------------------------------------------
 *  *
 *  * File Name:  HeapInterface.h
 *  * Author: Danny Tran
 *  * Description: HeapInterface header file
 *  * Date: 21 April 2017
 *  *
 *  ---------------------------------------------------------------------------- */

#ifndef HEAPINTERFACE_H
#define HEAPINTERFACE_H

#include <iostream>
#include <stdexcept>
#include <string>
//Heap Interface

template <typename T>
class HeapInterface
{
  public:
  virtual bool isEmpty() const = 0; //returns true if empty, false otherwise
  virtual int size() const = 0; //returns size of the heap
  virtual void add(T value) throw (std::runtime_error) = 0; //option to throw exception based on implementation
  virtual void remove() throw(std::runtime_error) = 0; //throws exception if there is nothing to remove
  virtual T peekTop() const throw(std::runtime_error)  = 0; //returns the item at the top of the heap
  virtual ~HeapInterface() { };
};
#endif
