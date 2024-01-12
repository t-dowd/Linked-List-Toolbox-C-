#ifndef LL_HPP
#define LL_HPP


#include <exception>
#include <iostream>
#include "Node.hpp"
// Gtest New Stuff
#include <sstream>
// #include "gtest/gtest.h"

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
     * @brief Size of the linked list
     * 
     */
    unsigned int mSize;

    /**
     * @brief Created a Node for the value of @param
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
     * @brief Get the Tail object
     * 
     * @return Node<T>* 
     */
    Node<T>* get_tail();
    
    /**
     * @brief Get the head object
     * 
     * @return Node<T>* 
     */
    Node<T>* get_head();
    
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
    

    void append(const T value);

    /**
     * @brief 
     * 
     * @param POS 
     * @param VALUE 
     */
    void insert(const int POS, const T VALUE);
    
    /**
     * @brief Removes a node from the linked List
     * 
     * @param POS 
     */
    void remove(const int POS);
        
    /**
     * @brief Finds max value in list.
     * 
     * @return Max out of list
     */
    T max(){};
    
    /**
     * @brief Finds min value in list.
     * 
     * @return Min out of list
     */
    T min();
    
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
LinkedList<T>::~LinkedList(){
    Node<T>* pCurrNode = new Node<T>;
    while (pCurrNode != nullptr){
        pCurrNode = mpHead;
        mpHead = mpHead->pNext;
        delete(pCurrNode);
    }
}
template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& OTHER){
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
Node<T>* LinkedList<T>::get_head(){
    return mpHead;
}

template <class T>
Node<T>* LinkedList<T>::get_tail(){
    return mpTail;
}

template <class T>
T LinkedList<T>::get(const int POS) const{
    Node<T>* pCurrNode = mpHead;
    if ((int)mSize <= 0 || mpHead == nullptr || (int)mSize <= (int)POS){
        // throw std::out_of_range("ERROR");
        return -1;
    }
    else{
        // for (int i = 0; i < mSize; i++){
        //     if (i == POS){
        //         return pCurrNode->value;
        //     }
        //     else{
        //         pCurrNode = pCurrNode->pNext;
        //     }
        // }
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
Node<T>* LinkedList<T>::MakeNodeForValue(T VALUE){
    Node<T>* pNewNode = new Node<T>;
    pNewNode->value = VALUE;
    pNewNode->pNext = nullptr;
    pNewNode->pPrev = nullptr;
    //iterate size
    mSize++;
    return pNewNode;
}
template <class T>
void LinkedList<T>::fullprint(){
const Node<T>* pCURR_NODE = mpHead;
    std::cout << "#  Printing    #" << 
        "\n[";
    if (pCURR_NODE == nullptr){
            std::cout << "NULLPNTRHEAD";
            return;
    }
    int counter = 0;
    // advance through list counting number of jumps and continue until position found or at end
    while(true){
        if (pCURR_NODE->pNext == nullptr || pCURR_NODE == nullptr){
            std::cout << " " << 
                pCURR_NODE->value <<
                "]"<<
                std::endl;
            return;
        }
        else{
            std::cout << " " <<
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
        int counter = 0;
        while(counter < POS){
            pCurrNode = pCurrNode->pNext;
            counter += 1;
        }
        pCurrNode->value = VALUE;
    }
}

template <class T>
void LinkedList<T>::append(const T VALUE){
    Node<T>* pNewNode = MakeNodeForValue(VALUE);
    mpTail->pNext = pNewNode;                                           /// Seg Fault Here somehow
    pNewNode->pPrev = mpTail;
    //set tail
    mpTail = pNewNode;
}
template <class T>
void LinkedList<T>::insert(const int POS, const T VALUE){
    Node<T>* pNewNode = MakeNodeForValue(VALUE);
        if(mpHead == nullptr) {
            mpHead = pNewNode;
            mpTail = pNewNode;
            return;
        }
        else if(POS >= (int)mSize-1){
            mpTail->pNext = pNewNode;
            pNewNode->pPrev=mpTail;

            mpTail = pNewNode;
        }
        else if( POS <= 0){
            pNewNode->pNext = mpHead;
            mpHead->pPrev = pNewNode;

            mpHead = pNewNode;
        }
        else{
            Node<T>* pCurrNode = mpHead;
            int counter = 0;
            while(counter < POS){
                pCurrNode = pCurrNode->pNext;
                counter++;
            }
        pNewNode->pNext=            pCurrNode;
        pNewNode->pPrev=            pCurrNode->pPrev;
        pCurrNode->pPrev->pNext=    pNewNode;
        pCurrNode->pPrev=           pNewNode;
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
        Node<T>* pNewNode = mpTail;
        
        // advance head

        // if we're now pointing at nothing
        if (pNewNode->pPrev == nullptr){
            //  set tail to also be null so it points to nothing
            mpHead = nullptr;
            mpTail = nullptr;
            return;
        }

        mpTail->pPrev->pNext = nullptr;
        mSize--;
        delete pNewNode;
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
    return true;
}
template <class T>
int LinkedList<T>::size(){
    return mSize;
}
template <class T>
int LinkedList<T>::find(const T VALUE){

    Node<T>* pNewNode = MakeNodeForValue(VALUE);
    for (unsigned int i = 0; i < mSize; i++){
        if (pNewNode->value == VALUE){
            return i;
        }
        else{
            pNewNode = pNewNode->pNext;
        }
    }
    return -1;

}
#endif