#include <iostream>
using namespace std;

// Define the Node class for the doubly linked list
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

// create a Doubly linked list.
class Doublylist
{
private:
    Node *head;
    Node *tail;

public:
    Doublylist()
    {
        head = tail = NULL;
    }

    // void push_front(int val)
    // {
    //     Node *newNode = new Node(val);
    //     if (head == NULL)
    //     {
    //         head = tail = newNode;
    //     }
    //     else
    //     {
    //         newNode->prev = tail;
    //         tail->next = newNode;
    //         tail = newNode;
    //     }
    // }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {

            head = tail = newNode;
        }
        else
        {

            tail->next = newNode;

            newNode->prev = tail;

            tail = newNode;
        }
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main()
{
    Doublylist myDoubly;

    myDoubly.push_back(1);
    myDoubly.push_back(2);
    myDoubly.push_back(3);

    myDoubly.print();

    return 0;
}