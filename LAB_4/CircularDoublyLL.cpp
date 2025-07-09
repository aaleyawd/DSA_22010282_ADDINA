/*
Name: Nur 'Aleya Addina Binti Mohd Wahid
Student ID: 22010282
Lab Group: G1
Lab Task: Lab 4 (Circular Doubly Linked List)
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;
    Node* prev_ptr;

    Node(const string& name) : name(name), next_ptr(nullptr), prev_ptr(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void add_element(const string& name) {
        Node* node = new Node(name);

        if (!head) {
            head = node;
            node->next_ptr = node;
            node->prev_ptr = node;
        }
        else {
            Node* tail = head->prev_ptr;

            tail->next_ptr = node;
            node->prev_ptr = tail;

            node->next_ptr = head;
            head->prev_ptr = node;
        }
    }

    void display_list() const {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->name << " <-> ";
            current = current->next_ptr;
        } while (current != head);
        cout << "(back to head)" << endl;
    }

    void delete_by_value(const string& val) {
        if (!head) return;

        Node* current = head;
        Node* to_delete = nullptr;

        do {
            if (current->name == val) {
                to_delete = current;
                break;
            }
            current = current->next_ptr;
        } while (current != head);

        if (!to_delete) return;

        // Only one node in the list
        if (to_delete->next_ptr == to_delete) {
            delete to_delete;
            head = nullptr;
            return;
        }

        // General case
        to_delete->prev_ptr->next_ptr = to_delete->next_ptr;
        to_delete->next_ptr->prev_ptr = to_delete->prev_ptr;

        // If deleting head, update it
        if (to_delete == head) {
            head = to_delete->next_ptr;
        }

        delete to_delete;
    }

    void clear() {
        if (!head) return;

        Node* current = head->next_ptr;
        while (current != head) {
            Node* temp = current;
            current = current->next_ptr;
            delete temp;
        }
        delete head;
        head = nullptr;
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

    // Memory automatically cleaned up by destructor

    return 0;
}
