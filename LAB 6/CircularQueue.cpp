/*
Name: Nur 'Aleya Addina Binti Mohd Wahid
Student ID: 22010282
Lab Group: G1
Lab Task: Lab 6 (Circular Queue)
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

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        clear();  // Automatically free memory
    }

    void enqueue(const string& name) {
        Node* node = new Node(name);

        if (!front) {
            front = rear = node;
            node->next_ptr = front;  // Circular link to self
        }
        else {
            rear->next_ptr = node;
            node->next_ptr = front;
            rear = node;
        }
    }

    void dequeue() {
        if (!front) {
            cout << "Queue is empty" << endl;
            return;
        }

        if (front == rear) { // Only one node
            cout << "Removing: " << front->name << endl;
            delete front;
            front = rear = nullptr;
        }
        else {
            Node* temp = front;
            cout << "Removing: " << temp->name << endl;
            front = front->next_ptr;
            rear->next_ptr = front;  // Maintain circularity
            delete temp;
        }
    }

    void display_queue() const {
        if (!front) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* current = front;
        cout << "Queue (front to rear): ";
        do {
            cout << current->name;
            current = current->next_ptr;
            if (current != front) cout << " <- ";
        } while (current != front);
        cout << endl;
    }

    void clear() {
        if (!front) return;

        rear->next_ptr = nullptr; // Break circular reference

        Node* current = front;
        while (current) {
            Node* temp = current;
            current = current->next_ptr;
            delete temp;
        }

        front = rear = nullptr;
    }
};

int main() {
    Queue queue;

    queue.enqueue("Ali");
    queue.enqueue("Ahmed");
    queue.enqueue("Alee");
    queue.enqueue("Abu");

    queue.display_queue();

    queue.dequeue();
    cout << "After Dequeue: ";
    queue.display_queue();

    // Memory automatically cleaned up by destructor
    return 0;
}
