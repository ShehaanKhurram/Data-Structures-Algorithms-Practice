#include <iostream>
using namespace std;

template <typename T>
void Sort(T* arr, int s) {
    for (int i = 0; i < s - 1; i++) {
        for (int j = 0; j < s - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); 
            }
        }
    }
}

template <typename T>
void input(T* arr, int s) {
    for (int i = 0; i < s; i++) {
        cin >> arr[i];
    }
}

template <typename T>
void output(T* arr, int s) {
    for (int i = 0; i < s; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int s;
    cout << "How many numbers do you want to enter?: ";
    cin >> s;

    cout << "1. Integer Number" << endl;
    cout << "2. Float Number"<<endl;
    cout << "Your Choice: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        int* arr = new int[s]; 
        cout << "Enter " << s << " integers: ";
        input(arr, s);
        Sort(arr, s);
        cout << "Sorted array: ";
        output(arr, s);
        delete[] arr;  
    }
    else if (choice == 2) {
        float* arr = new float[s]; 
        cout << "Enter " << s << " float numbers: ";
        input(arr, s);
        Sort(arr, s);
        cout << "Sorted array: ";
        output(arr, s);
        delete[] arr;  
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
