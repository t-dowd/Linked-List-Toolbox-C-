#ifndef LinkedList_hpp
#define LinkedList_hpp
#include <iostream>

// ~ ~ Base Object ~ ~ //
// for inheritance for future objects.

class Base {
   public:
   /**@brief Pure virtual function, allows the user to call display and will display all data dispite the differnet object types.*/
    virtual void display() const = 0;  
    // virtual Base get() const = 0;
    virtual ~Base() {}  // Virtual Destructor
};
template <class T>
class Derived : public Base{
    private:
        T data;
    public:
        Derived(const T& value ) : data(value) {}
        void display() const override{
            std::cout << data;
        }
};
// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ 
// If a user created object is needed edit below

// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ 
class LinkedList{
   private:

    // ~ Class Definition for Node ~ //
    // template <class T>
   class Node{
    public:
        Base* data;
        Node* _pNext;

        /*
        Notes for later ":" is an initalizer. Meaning
        that it will call the correlated constructor 
        in one operation. This is preferred because the
        object will not have to be reassigned, thus avoiding
        problems such as strange copy assignment operators. and lowers overhead!!! USE MORE!!!
        */ 

        Node(Base* obj) : data(obj), _pNext(nullptr) {}
        Base* _nodeGet(){
            return this->data;
        }
        // No need for destructor, it doesnt own the memory attached
        //   therefore it is pointless to have a destructor.
   };
   // ~ End class definition for Node ~ //
    Node* _mpHead;
    Node* _mpTail;

   public:
    LinkedList() : _mpHead(nullptr), _mpTail(nullptr) {};

    ~LinkedList(){
        Node* pCurrentNode = _mpHead;
        Node* pQueuedNode = nullptr;

        if(pCurrentNode == nullptr){
            // Empty or broken Linked List
            return;
        }
        while (pCurrentNode != nullptr){ 
            pQueuedNode = pCurrentNode->_pNext;
            delete pCurrentNode->data;
            delete pCurrentNode;
            pCurrentNode = pQueuedNode;
        }
        _mpHead = nullptr;
        _mpTail = nullptr;
    }
    /**
     * @brief Overloaded Derived function that accepts objects
     * 
     * @param object Any Object
     */
    void append(Base* object){
        Node* NewNode = new Node(object);
        if (_mpHead == nullptr) {
            _mpHead = NewNode;
            _mpTail = NewNode;
        } else {
            _mpTail->_pNext = NewNode;
            _mpTail = NewNode;
        }
    }
    
    Base* LLget(){
        return _mpHead->data;
    }

    void view(){
        Node* pCurrentNode = _mpHead;
        std::cout<<"[";
        while(pCurrentNode != nullptr){
            pCurrentNode->_nodeGet();
            pCurrentNode->data->display();
            if (pCurrentNode->_pNext != nullptr){ // Main Branch
                pCurrentNode = pCurrentNode->_pNext;
                std::cout<< " ";
            }
            else{
                pCurrentNode = pCurrentNode->_pNext;
            }
        }
        std::cout<<"]"<<std::endl;
    }

    
    
    void remove(){
        //
        return;
    }


    // ~ ~ ~ ~ ~ ~ Overoaded Append Functions ~ ~ ~ ~ ~ ~ ~ ~ // 


    // may need to update the appened functions to accpet user
    // defined objects. 
    /**
     * @brief The Append function for default value types. will not accept user defined objects.
     * 
     * @param value any default type
     */
    void append(int value){
        this->append(new Derived<int>(value)); //Is there an easier way to do it? yes. Do I know how? no.
    }
    /**
     * @brief The Append function for default value types. will not accept user defined objects.
     * 
     * @param value any default type
     */
    void append(float value){
        this->append(new Derived<float>(value));
    }
    /**
     * @brief The Append function for default value types. will not accept user defined objects.
     * 
     * @param value any default type
     */
    void append(std::string value){
        this->append(new Derived<std::string>(value));
    }
    /**
     * @brief The Append function for default value types. will not accept user defined objects.
     * 
     * @param value any default type
     */
    void append(int* value){
        this->append(new Derived<int*>(value));
    }
};



#endif