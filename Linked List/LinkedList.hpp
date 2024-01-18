#ifndef LL_HPP
#define LL_HPP


#include <exception>
#include <iostream>
#include "Node.hpp"
#include <sstream>
// #include "gtest/gtest.h"


/*
    Templated Linked List Project Written in C++
    Author: Thomas Dowd
*/

template <class T>
class LinkedList{
    
private:
    /**
     * @brief The Front of the LinkedList
     * 
     */
    Node<T>* mpHead;

    /**
     * @brief The Last Node in Linked List
     * 
     */
    Node<T>* mpTail;
    
    /**
     * @brief Number of objects stored in container
     * 
     */
    int mSize;

    /**
     * @brief Create a Node for a passed object's value
     * 
     * @param VALUE The Intended Value 
     * @return Node<T>* 
     */
    Node<T>* MakeNodeForValue(T VALUE);
public: 

/*~ ~ ~ Constructors ~ ~ ~*/ 
    /**
     * @brief Construct a new Linked List object
     * 
     */
    LinkedList();

    // See Copy Const...
    
    
/*~ ~ ~ Big Three ~ ~ ~*/ 
    /**
     * @brief Destroy the Linked List object.
     * 
     */
    ~LinkedList();
    /**
     * @brief Copy assignment operator
     * 
     * @param  
     * @return LinkedList& 
     */
    LinkedList& operator=(const LinkedList<T>&); // New Addition to this file, Normally this is omitted
    /**
     * @brief Copy Operator
     * 
     * @param OTHER linked list object to be constructed
     */
    LinkedList(const LinkedList<T>&);

/*~ ~ ~ Utility Functions ~ ~ ~*/ 

    /**
     * @brief Get the Tail Object Value
     * 
     * @return object stored within the node BY VALUE
     */
    T get_tail();
    
    /**
     * @brief Get the head Object
     * 
     * @return object stored within the node BY VALUE
     */
    T get_head();
    
    /**
     * @brief Returns object at given position.
     * 
     * @param POS Position of value to be returned
     * @return Object at position
     */
    T get(const int POS) const;
    
    /**
     * @brief Finds the object in the linked list, and returs the index of the object
     *        ! Will return -1 if it is unable to be found !
     * @param TARGET desired object
     * @return the index of object
     */
    int find(const T TARGET);

    /**
     * @brief 
     * 
     * @param POS 
     * @param VALUE 
     */
    void set(const int POS, const T VALUE);
    
    /**
     * @brief Pushes an object to the back of the linked list. 
     * 
     * @param VALUE object to be appended.
     */
    void append(const T VALUE);

    /**
     * @brief Allows for insertion into the linked list at an index.
     * 
     * @param POS Insert at an index
     * @param VALUE object to be inserted at a position.
     * 
     */
    void insert(const int POS, const T VALUE);
    
    /**
     * @brief Removes a node from the linked List
     * 
     * @param POS 
     */
    void remove(const int POS); 
    /**
     * @brief prints Full Linked list seperated by spaces
     * 
     */
    void fullprint();// Prints the Linked List
   
    /**
     * @brief Checks if the Linked List is Empty
     * 
     * @return true 
     * @return false 
     */
    bool isEmpty();
    /**
     * @brief Returns the allocated size of the Linked List
     * returns an int because who the fuck uses unisgned ints anymore
     * 
     * @return int 
     */
    int size();
};

template <class T>
LinkedList<T>::LinkedList(){
    mSize = 0;
    mpHead = nullptr;
    mpTail = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = mpHead;
    // Node<T>* current = MakeNodeForValue(mpHead->value);
    while (current != nullptr) {
        Node<T>* next;
        next = current->pNext;
        delete current;                         // ERROR HERE???
        current = next;
    }
    mpHead = nullptr;
    mpTail = nullptr;
    mSize = 0;
}
template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& OTHER){ // Needs Redux
    //delete everything in list
    while(mSize > 0){
        remove(0);
    }

    //iterate through New LinkedList and assign the values.
    Node<T>* pOTHERCurr = OTHER.mpHead;
    int counter = 0;
    while(pOTHERCurr != nullptr){
        insert(counter, pOTHERCurr->value);
        pOTHERCurr = pOTHERCurr->pNext;
        counter += 1;
    }
    return *this;
}
template <class T>
Node<T>* LinkedList<T>::MakeNodeForValue(T VALUE){
    Node<T>* pCurrNode = new Node<T>;
    pCurrNode->value = VALUE;
    pCurrNode->pNext = nullptr;
    pCurrNode->pPrev = nullptr;
    mSize++;
    return pCurrNode;
}

template <class T>
T LinkedList<T>::get_head(){
    return mpHead->value;
}
template <class T>
T LinkedList<T>::get_tail(){
    return mpTail->value;
}

template <class T>
T LinkedList<T>::get(const int POS) const{
    Node<T>* pCurrNode = mpHead;
    if ((int)mSize <= 0 || mpHead == nullptr || (int)mSize <= (int)POS){
        return -1;
    }
    else{
        int counter = 0;
        while(true){
            if(counter == POS){
                return pCurrNode->value;
            }
            if((pCurrNode->pNext == nullptr && counter != POS)|| (POS < 0 || POS <= counter) || (pCurrNode == nullptr)){
            // throw std::exception();
                // throw std::out_of_range("OUT OF RANGE");
                return -1;
            }
            else{
                pCurrNode = pCurrNode->pNext;
                counter++;
            }
        }
    }
    // throw std::out_of_range("ERROR");
    return -1;
}

template <class T>
void LinkedList<T>::fullprint(){
const Node<T>* pCURR_NODE = mpHead;
    std::cout << "#  Printing    #" << 
        "\n -->";
    if (pCURR_NODE == nullptr){
            std::cout << "NULLPNTRHEAD";
            return;
    }
    int counter = 0;
    // advance through list counting number of jumps and continue until position found or at end
    while(true){
        if (pCURR_NODE->pNext == nullptr || pCURR_NODE == nullptr){
            std::cout << " | " << 
                pCURR_NODE->value <<
                " |"<<
                std::endl;
            return;
        }
        else{
            std::cout << " | " <<
                pCURR_NODE->value; 
            pCURR_NODE = pCURR_NODE->pNext;
            counter += 1;
        }
    }
}
template <class T>
void LinkedList<T>::set(const int POS, const T VALUE){
    if((int)mSize <= POS || POS < 0 || mpHead == nullptr){
        return;
    }
    else{
        Node<T>* pCurrNode = mpHead;
        // int counter = 0;
        // while(counter < POS){
        //     pCurrNode = pCurrNode->pNext;
        //     counter += 1;
        // }
        // pCurrNode->value = VALUE;
        for (int counter = 0; counter < POS; ++counter) {  //This may be using Index rather than position.
            if (pCurrNode == nullptr) {
                // Handle the case where pCurrNode becomes null unexpectedly
                return;
            }
        pCurrNode = pCurrNode->pNext;
        }
        if (pCurrNode != nullptr) {
            pCurrNode->value = VALUE;
        }
    }
}

template <class T>
void LinkedList<T>::append(const T VALUE){
    Node<T>* pCurrNode = MakeNodeForValue(VALUE);
    // mpTail is null, meaning that mpHead must also be null
    if((mpHead == nullptr)/*Null Linked list, Fine*/|| (mpTail == nullptr) /*Broken Linked List, Screwed*/){
        mpHead = pCurrNode;
        mpTail = pCurrNode;
        // mSize++;
        return;
    }
    else{ // It is a valid Linked List, therefore we can make certian assumtions about the data. The biggest one being that mpTail is no longer Null.
        mpTail->pNext = pCurrNode;
        pCurrNode->pPrev = mpTail;
        mpTail = pCurrNode;
        // mSize++;
    }
}
template <class T>
void LinkedList<T>::insert(const int POS, const T VALUE){
    Node<T>* pCurrNode = MakeNodeForValue(VALUE);
        if(mpHead == nullptr) {
            // Empty, insert as head
            mpHead = pCurrNode;
            mpTail = pCurrNode;
            return;
        }
        else if(POS >= (int)mSize-1) { // Back Append
            this->append(VALUE);
        }
        else if( POS <= 0){ // Front Append
            pCurrNode->pNext = mpHead;
            mpHead->pPrev = pCurrNode;

            mpHead = pCurrNode;
        }
        else{
            Node<T>* pCurrNode = mpHead;
            int counter = 0;
            while(counter < POS && pCurrNode != nullptr){
                pCurrNode = pCurrNode->pNext;
                counter++;
            }
        pCurrNode->pNext=            pCurrNode;
        pCurrNode->pPrev=            pCurrNode->pPrev;
        pCurrNode->pPrev->pNext=    pCurrNode;
        pCurrNode->pPrev=           pCurrNode;
        }
}
template <class T>
void LinkedList<T>::remove(const int POS){
    if(mpHead == nullptr) {
        // do nothing
        return;
    } 
        // if position is before start of list
    else if(POS <= 0) {
        // remove from front
        //linked_list_remove_node_at_front(mpHead, mpTail);
        if(mpHead == nullptr) {
        // do nothing
        return;
        } 
        mpHead = mpHead->pNext;
        if(mpHead == nullptr){
            mpTail = nullptr;
        }
        else{
            mpHead->pPrev = nullptr;
        }
        mSize--;
        return;
    }
    else if (POS >= (int)mSize - 1){
            if(mpTail == nullptr) {
                // mpTail->pPrev->pNext = nullptr;
            return;
        }                
        if(mpTail->pPrev == nullptr){
            // delete pHead;
            // If broken maybe delete pTail?
            mpHead = nullptr;
            mpTail = nullptr;
            mSize--;
            return;
        }
        // store pointer to current head
        Node<T>* pCurrNode = mpTail;
        
        // advance head

        // if we're now pointing at nothing
        if (pCurrNode->pPrev == nullptr){
            //  set tail to also be null so it points to nothing
            mpHead = nullptr;
            mpTail = nullptr;
            return;
        }

        mpTail->pPrev->pNext = nullptr;
        mSize--;
        delete pCurrNode;
    }
     
    else {
        Node<T>* pCurrNode = mpHead;
        int counter = 0;
        // advance through list counting number of jumps and continue until position found or at end
        while(POS > counter && pCurrNode != nullptr){
                pCurrNode = pCurrNode->pNext;
                counter++;
            }
        if(pCurrNode == mpTail || pCurrNode == nullptr){
            if(mpTail == nullptr){
                return;
            }
            Node<T>* pTemp = mpTail;
            mpTail = pTemp->pPrev;
            if (mpTail == nullptr){
                mpHead = nullptr;
                return;
            }
            else{
                mpTail->pNext = nullptr;
            }
            delete pTemp;
            mSize--;
        }
        else{
        pCurrNode->pPrev->pNext = pCurrNode->pNext;
        pCurrNode->pNext->pPrev = pCurrNode->pPrev;
        mSize--;
        }
    }
}
template <class T>
bool LinkedList<T>::isEmpty(){
    return ((mSize == 0) && (mpHead == nullptr && mpTail == nullptr));
}
template <class T>
int LinkedList<T>::size(){
    return mSize;
}
template <class T>
int LinkedList<T>::find(const T VALUE){
    Node<T>* pCurrNode = MakeNodeForValue(VALUE);
    for (unsigned int i = 0; i < mSize; i++){
        if (pCurrNode == nullptr) {
            // Handle the case where pCurrNode becomes null unexpectedly
            return -1;
        }
        if (pCurrNode->value == VALUE){
            return i;
        }
        else{
            pCurrNode = pCurrNode->pNext;
        }
    }
    return -1;

}
#endif