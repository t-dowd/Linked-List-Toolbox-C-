#include "LinkedList.hpp"
#include <iostream>



int main(){

    LinkedList TestLL;
    

    /*
    this is how one can go about appending a user created function:
        F.append(new Derived<float>(1.234));
    if needed, once can create a user created object or modify the default one, using line 13 or 24 of th *.hpp file
    */

    // Append called implicitly
    TestLL.append(4);
    TestLL.append("A");
    // Append Called Explicity
    TestLL.append(new Derived<int>(1));
    TestLL.append(new Derived<std::string>("hello"));
    
    TestLL.view();  
    std::cout<< "Ran Main Successfully";
}