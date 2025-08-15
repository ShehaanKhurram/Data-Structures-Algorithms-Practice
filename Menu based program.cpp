#include <iostream>
using namespace std;

template <typename Type>
class List {
protected:
    Type* arr;
    int maxSize;
    int currentSize;

public:
    List(int size = 10) : maxSize(size), currentSize(0) {
        arr = new Type[maxSize];
    }

    List(const List& other) {
        maxSize = other.maxSize;
        currentSize = other.currentSize;
        arr = new Type[maxSize];
        for (int i = 0; i < currentSize; i++) {
            arr[i] = other.arr[i];
        }
    }

    virtual ~List() {
        delete[] arr;
    }

    virtual void addElementAtFirstIndex(Type element) = 0;
    virtual void addElementAtLastIndex(Type element) = 0;
    virtual Type removeElementFromEnd() = 0;
    virtual void removeElementFromStart() = 0;
};

class CustomList : public List<int> {
public:
    CustomList(int size = 10) : List<int>(size) {}
    CustomList(const CustomList& other) : List<int>(other) {}
    ~CustomList() {}

    void addElementAtFirstIndex(int element) override {
        if (currentSize >= maxSize) return;
        for (int i = currentSize; i > 0; i--) arr[i] = arr[i - 1];
        arr[0] = element;
        currentSize++;
    }

    void addElementAtLastIndex(int element) override {
        if (currentSize >= maxSize) return;
        arr[currentSize++] = element;
    }

    int removeElementFromEnd() override {
        if (currentSize == 0) return -1;
        return arr[--currentSize];
    }

    void removeElementFromStart() override {
        if (currentSize == 0) return;
        for (int i = 0; i < currentSize - 1; i++) arr[i] = arr[i + 1];
        currentSize--;
    }

    bool isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i * i <= num; i++)
            if (num % i == 0) return false;
        return true;
    }

    int sum_ofPrime() {
        int sum = 0;
        for (int i = 0; i < currentSize; i++)
            if (isPrime(arr[i])) sum += arr[i];
        return sum;
    }

    int secondMaxEven() {
        int max1 = -1, max2 = -1;
        for (int i = 0; i < currentSize; i++) {
            if (arr[i] % 2 == 0) {
                if (arr[i] > max1) {
                    max2 = max1;
                    max1 = arr[i];
                }
                else if (arr[i] > max2 && arr[i] != max1) {
                    max2 = arr[i];
                }
            }
        }
        return max2;
    }

    int secondMinOdd() {
        int min1 = 1e9, min2 = 1e9;
        for (int i = 0; i < currentSize; i++) {
            if (arr[i] % 2 != 0) {
                if (arr[i] < min1) {
                    min2 = min1;
                    min1 = arr[i];
                }
                else if (arr[i] < min2 && arr[i] != min1) {
                    min2 = arr[i];
                }
            }
        }
        return min2;
    }

    void printDuplicates() {
        bool found = false;
        for (int i = 0; i < currentSize; i++) {
            for (int j = i + 1; j < currentSize; j++) {
                if (arr[i] == arr[j]) {
                    cout << arr[i] << " ";
                    found = true;
                    break;
                }
            }
        }
        if (!found) cout << "No duplicates found.";
        cout << endl;
    }

    void rotateClockwise(int r) {
        if (currentSize < 2) return;
        int mid = currentSize / 2;
        r = r % mid;
        for (int j = 0; j < r; j++) {
            int temp = arr[mid - 1];
            for (int i = mid - 1; i > 0; i--) arr[i] = arr[i - 1];
            arr[0] = temp;
            temp = arr[currentSize - 1];
            for (int i = currentSize - 1; i > mid; i--) arr[i] = arr[i - 1];
            arr[mid] = temp;
        }
    }

    void rotateAntiClockwise(int rt) {
        if (currentSize < 2) return;
        int mid = currentSize / 2;
        rt = rt % mid;
        for (int j = 0; j < rt; j++) {
            int temp = arr[0];
            for (int i = 0; i < mid - 1; i++) arr[i] = arr[i + 1];
            arr[mid - 1] = temp;
            temp = arr[mid];
            for (int i = mid; i < currentSize - 1; i++) arr[i] = arr[i + 1];
            arr[currentSize - 1] = temp;
        }
    }
};

int main() {
    CustomList list(10);
    int choice, value;

    while (true) {
        cout << endl<<"Menu:"<<endl;
        cout << "1. Add Element at Start\n";
        cout << "2. Add Element at End\n";
        cout << "3. Remove Element from End\n";
        cout << "4. Remove Element from Start\n";
        cout << "5. Sum of Prime Numbers\n";
        cout << "6. Second Maximum Even Number\n";
        cout << "7. Second Minimum Odd Number\n";
        cout << "8. Print Duplicates\n";
        cout << "9. Rotate Clockwise\n";
        cout << "10. Rotate Anti-Clockwise\n";
        cout << "0. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.addElementAtFirstIndex(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.addElementAtLastIndex(value);
            break;
        case 3:
            cout << "Removed: " << list.removeElementFromEnd() << endl;
            break;
        case 4:
            list.removeElementFromStart();
            cout << "First element removed.\n";
            break;
        case 5:
            cout << "Sum of Prime Numbers: " << list.sum_ofPrime() << endl;
            break;
        case 6:
            cout << "Second Max Even: " << list.secondMaxEven() << endl;
            break;
        case 7:
            cout << "Second Min Odd: " << list.secondMinOdd() << endl;
            break;
        case 8:
            list.printDuplicates();
            break;
        case 9:
            cout << "Enter rotation count: ";
            cin >> value;
            list.rotateClockwise(value);
            break;
        case 10:
            cout << "Enter rotation count: ";
            cin >> value;
            list.rotateAntiClockwise(value);
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}
