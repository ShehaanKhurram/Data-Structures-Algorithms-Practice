#include <iostream>
#include <string>
#include<cstdlib>
#include<ctime>
using namespace std;

const int Array_Size = 5;

class Student {
public:
    string name;
    int score;
    int timeTaken;

    Student() {
        name = "";
        score = 0;
        timeTaken = 0;
    }
};

class Queue {
    Student* queue;
    int f;
    int b;

public:
    Queue() {
        queue = new Student[Array_Size];
        f = 0;
        b = 0;
    }

    ~Queue() {
        delete[] queue;
    }

    bool isFull() {
        return b == Array_Size;
    }

    bool isEmpty() {
        return f == b;
    }

    void Enqueue(Student s) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
        }
        else {
            queue[b++] = s;
        }
    }

    Student Front() {
        if (!isEmpty()) {
            return queue[f];
        }
        else {
            cout << "Queue is Empty!" << endl;
            return Student();
        }
    }

    void Dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
        }
        else {
            f++;
            if (f == b) {
                f = 0;
                b = 0;
            }
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
        }
        else {
            for (int i = f; i < b; i++) {
                cout << "Name: " << queue[i].name
                    << ", Score: " << queue[i].score
                    << ", Time Taken: " << queue[i].timeTaken << " mins" << endl;
            }
        }
    }
};

int main() {
    srand(time(0));  // Seed rand()

    Queue waitingQueue;
    Queue completedQueue;

    int choice;

    while (true) {
        cout << endl << "______Quiz Menu______" << endl;
        cout << "1. Add a student to the waiting queue" << endl;
        cout << "2. Start the quiz and generate scores" << endl;
        cout << "3. Display completed quiz results" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Student s;
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, s.name);
            s.score = 0;
            s.timeTaken = 0;
            waitingQueue.Enqueue(s);
            cout << "Student added to waiting queue." << endl;
        }
        else if (choice == 2) {
            if (waitingQueue.isEmpty()) {
                cout << "No students in waiting queue." << endl;
            }
            else {
                Student s = waitingQueue.Front();
                waitingQueue.Dequeue();

                s.score = rand() % 101;            // 0 to 100
                s.timeTaken = 5 + rand() % 26;      // 5 to 30

                completedQueue.Enqueue(s);
                cout << "Student '" << s.name << "' completed the quiz." << endl;

                if (waitingQueue.isEmpty()) {
                    cout << "All students have completed the quiz." << endl;
                }
            }
        }
        else if (choice == 3) {
            cout << endl << "____Quiz Results____" << endl;
            completedQueue.display();
        }
        else if (choice == 4) {
            cout << "Exiting..." << endl;
            break;
        }
        else {
            cout << "Invalid option. Try again." << endl;
        }
    }

    return 0;
}