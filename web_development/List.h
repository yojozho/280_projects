#ifndef LIST_H
#define LIST_H
/* List.h
 *
 * doubly-linked, double-ended list with Iterator interface
 * Project UID c1f28c309e55405daf00c565d57ff9ad
 * EECS 280 Project 4
 */

#include <iostream>
#include <cassert> //assert
#include <cstddef> //NULL


template <typename T>
class List {
  //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:
    
    List();
    
    List & operator=(const List &rhs);
    
    ~List();
    
  //EFFECTS:  returns true if the list is empty
  bool empty() const;

  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow.  Instead, keep track of the size
  //         with a private member variable.  That's how std::list does it.
  int size() const;

  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
  T & front();

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
  T & back();

  //EFFECTS:  inserts datum into the front of the list
  void push_front(const T &datum);

  //EFFECTS:  inserts datum into the back of the list
  void push_back(const T &datum);

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
  void pop_front();

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
  void pop_back();

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
  void clear();

  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you can omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists
    
private:
  //a private type
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };

  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
  void copy_all(const List<T> &other);

  void pop_all();

  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty
    int length = 0;

public:
  ////////////////////////////////////////
  class Iterator {
    //OVERVIEW: Iterator interface to List

    // You should add in a default constructor, destructor, copy constructor,
    // and overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you can omit them. A user
    // of the class must be able to create, copy, assign, and destroy Iterators.

    // Your iterator should implement the following public operators: *,
    // ++ (prefix), default constructor, == and !=.

  public:
    // This operator will be used to test your code. Do not modify it.
    // Requires that the current element is dereferenceable.
    Iterator() : node_ptr(nullptr) {}

    Iterator& operator--() {
      assert(node_ptr);
      node_ptr = node_ptr->prev;
      return *this;
    }
      
      Iterator &operator++() {
          assert(node_ptr);
          node_ptr = node_ptr->next;
          return *this;
      }
      
      T & operator*() const {
          assert(node_ptr);
          return node_ptr->datum;
    }
      
      bool operator==(Iterator rhs) const {
          return node_ptr == rhs.node_ptr;
      }

      bool operator!=(Iterator rhs) const {
          return node_ptr != rhs.node_ptr;
      }

  private:
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here

    // add any friend declarations here
      friend class List;
    // construct an Iterator at a specific position
      Iterator(Node *p) : node_ptr(p) {}

  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
  Iterator begin() const {
    return Iterator(first);
  }

  // return an Iterator pointing to "past the end"
    Iterator end() const {
        return Iterator();
    }

  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container
    void erase(Iterator i) {
        assert(i.node_ptr);
        if (i == begin()) {
            pop_front();
        }
        else if (i.node_ptr->datum == back()) {
            pop_back();
        }
        else {
            Node *victim = i.node_ptr;
            i.node_ptr->prev->next = i.node_ptr->next;
            i.node_ptr->next->prev = i.node_ptr->prev;
            delete victim;
            length -= 1;
        }
    }

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: inserts datum before the element at the specified position.
    void insert(Iterator i, const T &datum) {
        if (i == begin()) {
            push_front(datum);
        }
        else {
            Node *added = new Node {i.node_ptr,
                i.node_ptr->prev, datum};
            i.node_ptr->prev->next = added;
            i.node_ptr->prev = added;
            length += 1;
        }
    }

};//List


////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.

//List fuctions
template<typename T>
List<T>::List()
    : first(nullptr), last(nullptr) {}

template<typename T>
List<T> & List<T>::operator=(const List &rhs) {
    if (this != &rhs) {
        clear();
        copy_all(rhs);
    }
    return *this;
}

template<typename T>
List<T>::~List() {
    clear();
}

template<typename T>
bool List<T>::empty() const {
    return first == nullptr;
}

template<typename T>
int List<T>::size() const {
    return length;
}

template<typename T>
T & List<T>::front() {
    assert(!empty());
    return first->datum;
}

template<typename T>
T & List<T>::back() {
    assert(!empty());
    return last->datum;
}

template<typename T>
void List<T>::push_front(const T &datum) {
    Node *new_node;
    if (empty()) {
        new_node = new Node {nullptr, nullptr, datum};
        last = first = new_node;
    }
    else {
        new_node = new Node {first, nullptr, datum};
        first = first->prev = new_node;
    }
    length += 1;
}

template<typename T>
void List<T>::push_back(const T &datum) {
    Node *new_node;
    if (empty()) {
        new_node = new Node {nullptr, nullptr, datum};
        first = last = new_node;
    }
    else {
        new_node = new Node {nullptr, last, datum};
        last = last->next = new_node;
    }
    length += 1;
}

template<typename T>
void List<T>::pop_front() {
    assert(!empty());
    if (length > 1) {
        Node *victim = first;
        first = first->next;
        delete victim;
    }
    else{
        Node *victim = first;
        first = last = nullptr;
        delete victim;
    }
    length -= 1;
}

template<typename T>
void List<T>::pop_back() {
    assert(!empty());
    if (length > 1) {
        Node *victim = last;
        last = last->prev;
        delete victim;
    }
    else {
        Node *victim = last;
        last = first = nullptr;
        delete victim;
    }
    length -= 1;
}

template<typename T>
void List<T>::clear() {
    pop_all();
}

template<typename T>
void List<T>::copy_all(const List<T> &other) {
    for (Node * ptr = other.first;
         ptr != nullptr; ptr = ptr->next) {
        this->push_back(ptr->datum);
    }
}

template<typename T>
void List<T>::pop_all() {
    while (!empty()) {
        pop_front();
    }
}



#endif // Do not remove this. Write all your code above this line.
