/*
Name: Nur 'Aleya Addina Binti Mohd Wahid
Student ID: 22010282
Lab Group: G1
Lab Task: Lab 5 (Stack)
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

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        clear();  // Automatically clean up memory
    }

    void push(const string& name) {
        Node* node = new Node(name, top);
        top = node;
    }

    void pop() {
        if (!top) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        top = top->next_ptr;
        delete temp;
    }

    string peek() const {
        if (!top) {
            cout << "Stack is empty" << endl;
            return "";
        }
        return top->name;
    }

    void display_stack() const {
        if (!top) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* current = top;
        cout << "Stack (top to bottom): ";
        while (current) {
            cout << current->name;
            current = current->next_ptr;
            if (current) cout << " -> ";
        }
        cout << endl;
    }

    bool is_empty() const {
        return top == nullptr;
    }

    void clear() {
        while (top) {
            Node* temp = top;
            top = top->next_ptr;
            delete temp;
        }
    }
};

int main() {
    Stack stack;

    // Push elements
    stack.push("Ali");
    stack.push("Ahmed");
    stack.push("Alee");

    // Display the stack
    cout << "Initial stack: ";
    stack.display_stack();

    // Peek operation
    cout << "Top element: " << stack.peek() << endl;
    cout << "After peek: ";
    stack.display_stack();

    // Pop operation
    stack.pop();
    cout << "After pop: ";
    stack.display_stack();

    // No manual memory cleanup needed – handled by destructor
    return 0;
}
