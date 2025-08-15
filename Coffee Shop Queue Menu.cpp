#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 5;

class Queue {
    string* queue;
    int front, back;

public:
    Queue() {
        queue = new string[MAX_SIZE];
        front = 0;
        back = 0;
    }

    ~Queue() {
        delete[] queue;
    }

    bool isFull() {
        return back == MAX_SIZE;
    }

    bool isEmpty() {
        return front == back;
    }

    void enqueue(const string& name) {
        if (isFull()) {
            cout << "Queue is Full! Cannot add more customers." << endl;
            return;
        }
        queue[back++] = name;
        cout << name << " has been added to the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty! No customer to remove." << endl;
            return;
        }
        cout << queue[front] << " has been removed from the queue." << endl;
        front++;
    }

    void displayCount() {
        cout << "Number of customers in line: " << (back - front) << endl;
    }

    void viewFront() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
        }
        else {
            cout << "First customer in the queue: " << queue[front] << endl;
        }
    }

    void viewRear() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
        }
        else {
            cout << "Last customer in the queue: " << queue[back - 1] << endl;
        }
    }
};

int main() {
    Queue coffeeQueue;
    int choice;
    string name;

    while (true) {
        cout << endl;
        cout << "______Coffee Shop Queue Menu______" << endl;
        cout << "1. Add a customer to the queue" << endl;
        cout << "2. Remove the first customer from the queue" << endl;
        cout << "3. Display the number of customers in line" << endl;
        cout << "4. View the first customer in the queue" << endl;
        cout << "5. View the last customer in the queue" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter customer name: ";
            cin.ignore();
            getline(cin, name);
            coffeeQueue.enqueue(name);
            break;
        case 2:
            coffeeQueue.dequeue();
            break;
        case 3:
            coffeeQueue.displayCount();
            break;
        case 4:
            coffeeQueue.viewFront();
            break;
        case 5:
            coffeeQueue.viewRear();
            break;
        case 6:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid option! Try again." << endl;
        }
    }

    return 0;
}
