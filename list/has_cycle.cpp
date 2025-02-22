// 拿 GPT 写的，不用太纠结，其他链表题就不完整实现了

#include <iostream>
using namespace std;

class ListNode {
public:
    int value;  
    ListNode* next;  
    
    ListNode(int x) : value(x), next(nullptr) {}
};

class LinkedList {
public:
    ListNode* head;
    LinkedList() : head(nullptr) {}

    void insertAtHead(int value) {
        ListNode* newNode = new ListNode(value); 
        newNode->next = head; 
        head = newNode; 
    }

    void insertAtTail(int value) {
        ListNode* newNode = new ListNode(value); 
        if (head == nullptr) { 
            head = newNode;
        } else {
            ListNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;  
        }
    }

    void insertAtPosition(int value, int position) {
        if (position == 0) { 
            insertAtHead(value);
            return;
        }

        ListNode* newNode = new ListNode(value);
        ListNode* temp = head;

        for (int i = 0; i < position - 1; i++) {
            if (temp == nullptr) {
                cout << "Position out of range" << endl;
                return;
            }
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void printList() {
        ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

bool has_cycle(ListNode* head){
    ListNode* fast = head;
    ListNode* slow = head;

    while(fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast) return true;
    }

    return false;
}

int main() {
    LinkedList list;  

    list.insertAtHead(10); 
    list.insertAtTail(20); 
    list.insertAtTail(30); 
    list.insertAtPosition(25, 2);

    cout << "Linked list: ";
    list.printList();

    if (has_cycle(list.head)) {
        cout << "Has cycle!" << endl;
    } else {
        cout << "No cycle!" << endl;
    }

    return 0;
}