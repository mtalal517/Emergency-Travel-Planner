#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <ctime>
#include <cmath>
using namespace std;

class Node
{
public:
    int value;
    Node* next;

    Node(int x)
    {
        value = x;
        next = nullptr;
    }
};

class Queue
{
public:
    Node* front;
    Node* rear;

    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(int data)
    {
        Node* newNode = new Node(data);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty " << endl;
            return -1;
        }

        int data1 = front->value;
        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        return data1;
    }

    int Front()
    {
        if (isEmpty())
        {
            cout << "Queue Empty " << endl;
            return -1;
        }

        return front->value;
    }

};
