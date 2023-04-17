#include <vector>
#include <iostream>

using namespace std;

struct Node {
    int value;
    int count;
    Node* next;
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void add(int value);
    bool remove(int value);
    void printList() const;
    void createList(const std::vector<int>& values);
    int sumNodes() const;

private:
    Node* head;
};
void insert(vector<int>& values, int firstValue, int secondValue);
