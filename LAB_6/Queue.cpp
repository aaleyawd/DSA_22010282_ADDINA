/*
Name: Nur 'Aleya Addina Binti Mohd Wahid
Student ID: 22010282
Lab Group: G1
Lab Task: Lab 6 (Queue)
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
        clear();
    }

    void enqueue(const string& name) {
        Node* node = new Node(name);
        if (!front) {
            front = rear = node;
        }
        else {
            rear->next_ptr = node;
            rear = node;
        }
    }

    void dequeue() {
        if (!front) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        cout << "Removing: " << temp->name << endl;
        front = front->next_ptr;

        if (!front) {
            rear = nullptr; // If queue becomes empty, reset rear too
        }

        delete temp;
    }

    void display_queue() const {
        if (!front) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* current = front;
        cout << "Queue (front to rear): ";
        while (current) {
            cout << current->name;
            if (current->next_ptr) cout << " <- ";
            current = current->next_ptr;
        }
        cout << endl;
    }

    void clear() {
        while (front) {
            Node* temp = front;
            front = front->next_ptr;
            delete temp;
        }
        rear = nullptr;
    }
};

int main() {
    Queue queue;

    queue.enqueue("Ali");
    queue.enqueue("Ahmed");
    queue.enqueue("Alee");
    queue.enqueue("Abu");

    cout << "Initial Queue: ";
    queue.display_queue();

    queue.dequeue();
    cout << "After Dequeue: ";
    queue.display_queue();

    // Memory is automatically cleaned up by destructor
    return 0;
}
