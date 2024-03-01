#include <iostream>
#include "Node.hpp"
#include "LinkedList.hpp"
// Gtest New Stuff
#include <sstream>

int main(){
    
    // Simple 
    LinkedList <int>* GQ = new LinkedList<int>();
    GQ->append(1);
    GQ->append(12345);
    GQ->append(12345);
    GQ->append(12345);
    GQ->fullprint();
    delete GQ;
}