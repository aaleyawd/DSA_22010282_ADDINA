/*
Name: Nur 'Aleya Addina Binti Mohd Wahid
Student ID: 22010282
Lab Group: G1
Lab: Lab 4 (Circular Singly Linked List)
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;

    Node(const string& name) : name(name), next_ptr(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void add_element(const string& name) {
        Node* node = new Node(name);

        if (!head) {
            head = tail = node;
            node->next_ptr = node; // Circular reference
        }
        else {
            tail->next_ptr = node;
            node->next_ptr = head;
            tail = node;
        }
    }

    void display_list() const {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->name << " -> ";
            current = current->next_ptr;
        } while (current != head);
        cout << "head (" << head->name << ")" << endl;
    }

    void delete_by_value(const string& val) {
        if (!head) return;

        Node* current = head;
        Node* prev = tail;
        do {
            if (current->name == val) {
                if (current == head) {
                    if (head == tail) {
                        delete head;
                        head = tail = nullptr;
                    }
                    else {
                        head = head->next_ptr;
                        tail->next_ptr = head;
                        delete current;
                    }
                }
                else {
                    prev->next_ptr = current->next_ptr;
                    if (current == tail) {
                        tail = prev;
                    }
                    delete current;
                }
                return;
            }
            prev = current;
            current = current->next_ptr;
        } while (current != head);
    }

    void clear() {
        if (!head) return;

        Node* current = head;
        tail->next_ptr = nullptr; // Break circular reference

        while (current) {
            Node* temp = current;
            current = current->next_ptr;
            delete temp;
        }

        head = tail = nullptr;
    }
};

int main() {
    LinkedList linkedlst;

    linkedlst.add_element("Ali");
    linkedlst.add_element("Ahmed");
    linkedlst.add_element("Alee");

    cout << "Original list: ";
    linkedlst.display_list();

    linkedlst.delete_by_value("Ahmed");
    cout << "After deleting Ahmed: ";
    linkedlst.display_list();

    // No manual memory cleanup needed — handled by destructor
    return 0;
}
