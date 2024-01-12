#ifndef The_Brick
#define The_Brick

#include <iostream>
#include <cstdlib>
#include <ctime>

/**
 * @brief A intentionally dense arbitrary class for the purpose of testing containers. Not entierly sure how it works.
 * 
 */
template <typename T>
class TestBrick {
private:
    long long int RandomVariable;
    // T* dynamicallyStoredVariable;
public:
    // Default constructor that initializes with random values
    TestBrick() {
        srand(static_cast<unsigned>(time(nullptr)));
        RandomVariable = rand(); // Range can be implemented here.
        // dynamicallyStoredVariable = new T(rand() % 100); // Dynamically allocate and initialize with a random value
    }

    // Destructor to free dynamically allocated memory
    ~TestBrick() {
        // delete dynamicallyStoredVariable;
    }

    // Getter for the templated variable
    int getRandomVariable() const {
        return RandomVariable;
    }

    // Getter for the dynamically stored variable
    // T getDynamicallyStoredVariable() const {
        // return *dynamicallyStoredVariable;

    // Function to make it purposefully difficult for the LinkedList class
    void doSomethingComplex() {
        // Example: Modify the templated variable
        RandomVariable = rand() % 100;
        // Example: Modify the dynamically stored variable
        // *dynamicallyStoredVariable = rand() % 100;

        if (rand() % 100 == 0) {
            // Attempt to access unallocated memory to be intionally painfull
            // dynamicallyStoredVariable = nullptr;
            for (int i = 0; i < 10000; i++){
                RandomVariable *=2;
            }
            // *dynamicallyStoredVariable = 42;  // Accessing unallocated memory
        }
    }
};

#endif
