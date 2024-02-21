#ifndef NODE_HPP
#define NODE_HPP


/*
    Templated Linked List Project Written in C++
    Author: Thomas Dowd
*/


/**
 * @brief A single element of a linked list or can be implemented into any other another similar function
 * 
 */
template <class T>
struct Node {
    /**
     * @brief the value of this Node
     * 
     */
    T value;
    
    /**
     * @brief pointer to the next element of the linked list
     * 
     */
    Node<T> *pNext;
    
    /**
     * @brief pointer to the previous element of the linked list
     * 
     */
    Node<T> *pPrev;
    // Staged Copy assignmet Op for Node.cpp in case it is needed.
    // // Copy assignment operator
    // Node<T>& operator=(const Node<T>& other) {
    //     if (this != &other) {
    //         value = other.value;
    //         // Perform any additional copying if necessary
    //     }
    //     return *this;
    // }
};
#endif