#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtPosition(int value, int position) {
        if (position == 1) {
            insertAtHead(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position out of bounds." << endl;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteNode(int value) {
        if (head == nullptr) 
            return;

        if (head->data == value) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Value not found." << endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    int length() {
        int len = 0;
        Node* temp = head;
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    bool search(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    bool detectLoop() {
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }

    void deleteNthFromEnd(int n) {
        Node* dummy = new Node(0);
        dummy->next = head;
        Node* first = dummy;
        Node* second = dummy;

        for (int i = 0; i <= n; i++) {
            if (first == nullptr) return;
            first = first->next;
        }

        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        Node* toDelete = second->next;
        second->next = second->next->next;
        delete toDelete;

        head = dummy->next;
        delete dummy;
    }

    
    static Node* mergeSortedLists(Node* l1, Node* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        Node* result = nullptr;

        if (l1->data < l2->data) {
            result = l1;
            result->next = mergeSortedLists(l1->next, l2);
        }
        else {
            result = l2;
            result->next = mergeSortedLists(l1, l2->next);
        }
        return result;
    }

    Node* getHead() {
        return head;
    }

    void setHead(Node* node) {
        head = node;
    }
};

int main() {
    LinkedList list;

    cout << "Insert elements at end: 1, 2, 3" << endl;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.display();

    cout << "Insert 0 at beginning:" << endl;
    list.insertAtHead(0);
    list.display();

    cout << "Insert 5 at position 3:" << endl;
    list.insertAtPosition(5, 3);
    list.display();

    cout << "Length of list: " << list.length() << endl;

    cout << "Searching for 5: " << (list.search(5) ? "Found" : "Not Found") << endl;

    cout << "Deleting 2:" << endl;
    list.deleteNode(2);
    list.display();

    cout << "Reversing the list:" << endl;
    list.reverse();
    list.display();

    cout << "Testing loop detection (without loop): " << (list.detectLoop() ? "Loop Found" : "No Loop") << endl;

    LinkedList list1, list2;
    list1.insertAtTail(1);
    list1.insertAtTail(4);
    list1.insertAtTail(7);

    list2.insertAtTail(2);
    list2.insertAtTail(3);
    list2.insertAtTail(8);

    Node* mergedHead = LinkedList::mergeSortedLists(list1.getHead(), list2.getHead());

    LinkedList mergedList;
    mergedList.setHead(mergedHead);

    cout << "Merged sorted lists:" << endl;
    mergedList.display();

    cout << "Deleting 2nd node from end of merged list:" << endl;
    mergedList.deleteNthFromEnd(2);
    mergedList.display();

    return 0;
}
