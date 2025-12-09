#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *pNext;
};

struct List {
    Node *pHead;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->pNext = NULL;
    return newNode;
}

bool isEmpty(List list) {
    return (list.pHead == NULL);
}

void addHead(List& list, Node* node) {
    if (list.pHead == NULL) {
        list.pHead = node;
    } else {
        node->pNext = list.pHead;
        list.pHead = node;
    }
}

void addTail(List& list, Node* node) {
    if (list.pHead == NULL) {
        list.pHead = node;
    } else {
        Node* temp = list.pHead;
        while (temp->pNext != NULL) {
            temp = temp->pNext;
        }
        temp->pNext = node;
    }
}

void displayList(List list) {
    Node* temp = list.pHead;
    while (temp!=NULL) {
        cout << temp->value << " ";
        temp=temp->pNext;
    }
    cout << endl;
}

Node* findByValue(List list, int fValue) {
    Node* temp = list.pHead;
    while (temp != NULL) {
        if (temp->value == fValue) {
            return temp;
        }
        temp = temp->pNext;
    }
    return nullptr;
}

void deleteHead(List& list) {
    Node* temp = list.pHead;
    Node* newHead = temp->pNext;
    delete temp;
    list.pHead = newHead;
}

int main() {
    List list;
    list.pHead = NULL;
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);

    addHead(list,node1);
    addTail(list,node2);
    addTail(list,node3);
    addTail(list,node4);

    // Node* findResult = findByValue(list,3);
    // cout << findResult->value << endl;
    deleteHead(list);
    displayList(list);
    cout << (node1->value);
    return 0;
}