/*
Name: Nur 'Aleya Addina Binti Mohd Wahid
Student ID: 22010282
Lab Group: G1
Lab Task: Lab 3 (Doubly Linked List)
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;
    Node* prev_ptr;

    Node(string name, Node* next_ptr = nullptr, Node* prev_ptr = nullptr)
        : name(name), next_ptr(next_ptr), prev_ptr(prev_ptr) {
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        clear(); // Automatically clean up memory
    }

    void add_element(const string& name) {
        Node* node = new Node(name);

        if (!head) {
            head = tail = node;
        }
        else {
            tail->next_ptr = node;
            node->prev_ptr = tail;
            tail = node;
        }
    }

    void display_list() const {
        Node* current = head;
        if (!current) {
            cout << "List is empty" << endl;
            return;
        }

        while (current) {
            cout << current->name << " <-> ";
            current = current->next_ptr;
        }
        cout << "nullptr" << endl;
    }

    void delete_by_value(const string& val) {
        if (!head) return;

        Node* current = head;

        // Deleting head
        if (current->name == val) {
            head = head->next_ptr;
            if (head) head->prev_ptr = nullptr;
            else tail = nullptr;
            delete current;
            return;
        }

        while (current && current->name != val) {
            current = current->next_ptr;
        }

        if (!current) return; // Not found

        if (current->prev_ptr) current->prev_ptr->next_ptr = current->next_ptr;
        if (current->next_ptr) current->next_ptr->prev_ptr = current->prev_ptr;
        if (current == tail) tail = current->prev_ptr;

        delete current;
    }

    void clear() {
        Node* current = head;
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

    // Add elements
    linkedlst.add_element("Ali");
    linkedlst.add_element("Ahmed");
    linkedlst.add_element("Alee");

    // Display the list
    cout << "Original list: ";
    linkedlst.display_list();

    // Delete a node
    linkedlst.delete_by_value("Ahmed");
    cout << "After deleting Ahmed: ";
    linkedlst.display_list();

    // Memory automatically cleaned up by destructor

    return 0;
}
