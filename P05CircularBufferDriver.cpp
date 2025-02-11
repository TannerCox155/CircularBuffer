// P05CircularBufferDriver.cpp -- Driver file for circular buffer
// Tanner Cox - CS-318 - Fall 2024

/*  REQUIREMENTS NOTES:

    Fill in the remainder of this driver program.
    Replicate exactly the sample run provided with project's specs.
    Use a capacity of 5
*/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "circular_buffer.h"
#include "dog.h"

using namespace std;

int main() {
    cout << "\n*************** <int> Circular Buffer Demo ******************\n\n";
    //  FINISH THIS SECTION
    CircularBuffer<int, 5> buffer;

    cout << "Initial state\n" << buffer;
    
    // Loop and push values into the buffer (i * 10) to match project specifications for output
    // Display buffer after each push
    for (int i = 0; i <= 7; ++i) {
        cout << "Pushing " << (i * 10) << "\n";
        buffer.push_back(i * 10);
        cout << buffer;
    }
   
    // Loop and pop values from the buffer and display after each pop.
    for (int i = 0; i < 5; ++i) {
        cout << "Popping " << (i + 3) * 10 << "\n";
        buffer.pop();
        cout << buffer;
    }

    cout << "\n*************** <string> Circular Buffer Demo ******************\n\n";

    // FINISH THIS SECTION --
    // create a vector of words
    // use back_insert_iterator to fill the buffer

    CircularBuffer<string, 5> bufferStr;
    vector<string> oz = { "welcome", "to", "the", "wonderful", "world", "of", "oz" };
    cout << "Initial state\n" << bufferStr;

    copy(oz.begin(), oz.end(), back_inserter(bufferStr));
    cout << "After using back_insert_iterator\n" << bufferStr;

    bufferStr.pop();
    cout << "Popping: the\n" << bufferStr;
    bufferStr.pop();
    cout << "Popping: wonderful\n" << bufferStr;
    bufferStr.pop();
    cout << "Popping: world\n" << bufferStr;
    bufferStr.pop();
    cout << "Popping: of\n" << bufferStr;   
    bufferStr.pop();
    cout << "Popping: oz\n" << bufferStr;

    cout << "\n*************** <Dog> Circular Buffer Demo ******************\n\n";

    //  FINISH THIS SECTION
  
    CircularBuffer<dog, 5> bufferDog;
    string full;
    
    dog guinness("Guinness", "Wheaten", 9);
    dog grimlock("Grimlock", "Lab", 2);
    dog optimus("Optimus", "Bulldog", 5);
    dog murphy("Murphy", "Lab", 14);
    dog floyd("Floyd", "Beagle", 12);
    dog snoopy("Snoopy", "Beagle", 100);
    dog archie("Archie", "Brittany", 1);
    dog penny("Penny", "Beagle", 2);
    
    vector<dog> vDog = { guinness, grimlock, optimus, murphy, floyd};
    
    // Loop through vector of dog objects and push_back
    for (int i = 0; i < vDog.size(); ++i) {
        bufferDog.push_back(vDog[i]);
    }
    
    cout << bufferDog;
    
    if (bufferDog.full()) {
        full = "true";
    }
    else { full = "false"; }

    cout << "dogs full?:" << full << "\n\n";
    
    // Pushing back the last remaining dog objects
    bufferDog.push_back(snoopy);
    cout << bufferDog; 

    bufferDog.push_back(archie);
    cout << bufferDog;

    bufferDog.push_back(penny);
    cout << bufferDog;

    // Pop remaining dog objects from buffer
    bufferDog.pop();
    cout << "Popping:";
    cout << murphy << "\n\n";
    cout << bufferDog;

    bufferDog.pop();
    cout << "Popping:";
    cout << floyd << "\n\n";
    cout << bufferDog;

    bufferDog.pop();
    cout << "Popping:";
    cout << snoopy << "\n\n";
    cout << bufferDog;

    bufferDog.pop();
    cout << "Popping:";
    cout << archie << "\n\n";
    cout << bufferDog;

    bufferDog.pop();
    cout << "Popping:";
    cout << penny << "\n\n";
    cout << bufferDog;

    cout << endl;
}