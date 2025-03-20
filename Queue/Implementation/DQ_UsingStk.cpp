#include <iostream>
#include <stdexcept> // For exceptions
using namespace std;

// round Robin fashion is allowed and has to be followed

int mx_size = 1000;

class Q {
    int* arr;
    int f;
    int r;

public:
    Q() {
        arr = new int[mx_size]; // Initialize the array with maximum size
        f = -1; // Front index, -1 indicates empty queue
        r = -1; // Rear index, -1 indicates empty queue
    }

    ~Q() {
        delete[] arr; // Destructor to release memory
    }

    bool isFull() {
        return (r + 1) % mx_size == f; // Check if the queue is full using the modulo operator to handle circularity
    }

    bool isEmpty() {
        return f == -1; // Check if the queue is empty
    }

    void pushBack(int data) {
        if (isFull()) {
            throw std::overflow_error("Queue Overflow"); // Throw exception if queue is full
        }
        if (isEmpty()) {
            f = 0; // If queue is empty, initialize front to 0
        }
        r = (r + 1) % mx_size; // Increment rear index in a circular manner
        arr[r] = data; // Insert data at the rear
    }

    int popFront() {
        if (isEmpty()) {
            throw std::underflow_error("Queue Underflow"); // Throw exception if queue is empty
        }
        int temp = arr[f]; // Store the data at the front
        arr[f] = -1; // Or some other sentinel value
        if (f == r) {
            // Last element
            f = -1; // Reset front and rear to -1, making the queue empty
            r = -1;
        }
        else {
            f = (f + 1) % mx_size; // Increment front index in a circular manner
        }
        return temp; // Return the data at the front
    }

    int popBack() {
        if (isEmpty()) {
            throw std::underflow_error("Queue Underflow"); // Throw exception if queue is empty
        }
        int temp = arr[r]; // Store the data at the rear
        arr[r] = -1; // Or some other sentinel value
        if (f == r) {
            // Last element
            f = -1; // Reset front and rear to -1, making the queue empty
            r = -1;
        }
        else {
            r = (r - 1 + mx_size) % mx_size; // Ensure r stays non-negative
        }
        return temp; // Return the data at the rear
    }

    void pushFront(int data) {
        if (isFull()) {
            throw std::overflow_error("Queue Overflow"); // Throw exception if queue is full
        }
        if (f == -1) {
            f = 0; // If queue is empty, initialize front and rear to 0
            r = 0;
        }
        else {
            f = (f - 1 + mx_size) % mx_size; // Ensure f stays non-negative
        }
        arr[f] = data; // Insert data at the front
    }
};