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




#endif