#include <iostream>
#include "Node.hpp"
#include "LinkedList.hpp"
// Gtest New Stuff
#include <sstream>

int main(){
    // LinkedList <BaseObject*> GQ ;

    // objectList.push_back(new IntegerObject(42));
    // objectList.push_back(new StringObject("Hello, World!"));
    // Free Store ~ ~ ~ ~
    LinkedList <int>* GQ = new LinkedList<int>();
    GQ->append(1);
    GQ->append(12345);
    GQ->append(12345);
    GQ->append(12345);
    GQ->fullprint();
    delete GQ;

    std::cout<<"you've successfully ran main" <<std::endl;
}