/*
Name: Nur 'Aleya Addina Binti Mohd Wahid
Student ID: 22010282
Lab Group: G1
Lab: Lab 3 (Singly Linked List)
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_ptr;

    Node(const string& name, Node* next_ptr = nullptr)
        : name(name), next_ptr(next_ptr) {
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        clear();  // Automatically free memory when object is destroyed
    }

    void add_element(const string& name) {
        Node* node = new Node(name);

        if (!head) {
            head = tail = node;
        }
        else {
            tail->next_ptr = node;
            tail = node;
        }
    }

    void display_list() const {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }

        Node* current = head;
        while (current) {
            cout << current->name << " -> ";
            current = current->next_ptr;
        }
        cout << "nullptr" << endl;
    }

    void delete_by_value(const string& val) {
        if (!head) return;

        // Special case: delete head
        if (head->name == val) {
            Node* temp = head;
            head = head->next_ptr;
            delete temp;
            if (!head) tail = nullptr; // Update tail if list is now empty
            return;
        }

        Node* current = head;
        while (current->next_ptr && current->next_ptr->name != val) {
            current = current->next_ptr;
        }

        if (current->next_ptr) {
            Node* temp = current->next_ptr;
            current->next_ptr = temp->next_ptr;
            if (temp == tail) tail = current;
            delete temp;
        }
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

    // Display list
    cout << "Original list: ";
    linkedlst.display_list();

    // Delete a node
    linkedlst.delete_by_value("Ahmed");
    cout << "After deleting Ahmed: ";
    linkedlst.display_list();

    // No need to manually delete nodes — handled by destructor
    return 0;
}
