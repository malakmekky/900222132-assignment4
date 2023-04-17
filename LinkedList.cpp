#include "LinkedList.h"
#include <vector>
#include <iostream>

using namespace std;

LinkedList::LinkedList() : head(nullptr) {}

void LinkedList::add(int value) {
    if (head == nullptr) {
        head = new Node{ value, 1, nullptr };
    }
    else {
        Node* current = head;
        while (current->next != nullptr && current->value != value) {
            current = current->next;
        }
        if (current->value == value) {
            current->count++;
        }
        else {
            current->next = new Node{ value, 1, nullptr };
        }
    }
}

bool LinkedList::remove(int value) {
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr && current->value != value) {
        prev = current;
        current = current->next;
    }
    if (current == nullptr) {
        return false;
    }
    if (current->count > 1) {
        current->count--;
    }
    else {
        if (prev == nullptr) {
            head = current->next;
        }
        else {
            prev->next = current->next;
        }
        delete current;
    }
    return true;
}

void LinkedList::printList() const {
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << "(" << current->count << ") ";
        current = current->next;
    }
    cout << endl;
}

void LinkedList::createList(const std::vector<int>& values) {
    for (int value : values) {
        add(value);
    }
}

int LinkedList::sumNodes() const {
    Node* current = head;
    int sum = 0;
    while (current != nullptr) {
        sum += current->value * current->count;
        current = current->next;
    }
    return sum;
}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void insert(vector<int>& values, int num1, int num2) {
    for (int i = 0; i < values.size(); i++) {
        if (values[i] == num1) {
            values.insert(values.begin() + i + 1, num2);
            i++;
        }
    }
}

int main() {
    //create linked list
    int n, num1, num2;
    cout << "Enter the number of integers: ";
    cin >> n;
    vector<int> values(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    // add to vector
    insert(values, num1, num2);

    // create modified linked list
    LinkedList list;
    list.createList(values);

    // output linked list
    cout << "Linked List: ";
    list.printList();
    cout << "Sum of nodes: " << list.sumNodes() << endl;

    // remove node
    int removeValue;
    cout << "Enter a value to remove: ";
    cin >> removeValue;
    if (list.remove(removeValue)) {
        cout << "New Linked List: ";
        list.printList();
        cout << "Sum: " << list.sumNodes() << endl;
    }
    else {
        cout << removeValue << " not found in the linked list." << endl;
    }

    return 0;
}
