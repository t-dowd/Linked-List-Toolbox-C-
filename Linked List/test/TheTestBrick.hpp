#ifndef The_Brick
#define The_Brick

#include <iostream>
#include <cstdlib>
#include <ctime>

// A templated class for the TestBrick
template <typename T>
class TestBrick {
private:
    T templatedVariable;
    T* dynamicallyStoredVariable;

public:
    // Default constructor that initializes with random values
    TestBrick() {
        srand(static_cast<unsigned>(time(nullptr)));
        templatedVariable = rand() % 100; // Example: Use rand() % some_range to get a random value
        dynamicallyStoredVariable = new T(rand() % 100); // Dynamically allocate and initialize with a random value
    }

    // Destructor to free dynamically allocated memory
    ~TestBrick() {
        delete dynamicallyStoredVariable;
    }

    // Getter for the templated variable
    T getTemplatedVariable() const {
        return templatedVariable;
    }

    // Getter for the dynamically stored variable
    T getDynamicallyStoredVariable() const {
        return *dynamicallyStoredVariable;
    }

    // Function to make it purposefully difficult for the LinkedList class
    void doSomethingComplex() {
        // Perform some complex operations here
        // ...

        // Example: Modify the templated variable
        templatedVariable = rand() % 100;

        // Example: Modify the dynamically stored variable
        *dynamicallyStoredVariable = rand() % 100;
    }
};

#endif
