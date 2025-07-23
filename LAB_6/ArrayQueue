/*
Name: Nur 'Aleya Addina Binti Mohd Wahid
Student ID: 22010282
Lab Group: G1
Lab: Lab 6 (Array Queue)
*/

#include <iostream>
#include <string>
using namespace std;

class Queue
{
private:
    string *arr;
    int front;
    int rear;
    int capacity;
    int currentSize;

public:
    Queue(int size = 100)
    {
        capacity = size;
        arr = new string[capacity];
        front = 0;
        rear = -1;
        currentSize = 0;
    }

    ~Queue() // Destructor to avoid memory leaks
    {
        delete[] arr;
    }

    bool isEmpty() const
    {
        return currentSize == 0;
    }

    bool isFull() const
    {
        return currentSize == capacity;
    }

    void enqueue(const string &name)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue '" << name << "'." << endl;
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = name;
        currentSize++;
        cout << "Enqueued: " << name << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;
        front = (front + 1) % capacity;
        currentSize--;
    }

    void display_queue() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue contents: ";
        int index = front;
        for (int i = 0; i < currentSize; i++)
        {
            cout << arr[index];
            if (i != currentSize - 1)
                cout << " <- ";
            index = (index + 1) % capacity;
        }
        cout << endl;
    }
};

int main()
{
    Queue queue(10);

    // Simulate user interaction
    queue.enqueue("Ali");
    queue.enqueue("Ahmed");
    queue.enqueue("Alee");
    queue.enqueue("Abu");

    queue.display_queue();

    queue.dequeue();
    queue.dequeue();

    queue.display_queue();

    return 0;
}
