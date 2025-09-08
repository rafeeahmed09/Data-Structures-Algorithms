
#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class queue
{
    node *head;
    node *tail;

public:
    queue()
    {
        head = NULL;
        tail = NULL;
    }
    void push(int val)
    {
        node *newnode = new node(val);
        if (empty())
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void pop()
    {
        if (empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        node *temp = head;
        head = head->next;
        delete temp;
    }

    int front()
    {
        if (empty())
        {
            cout << "queue is empty" << endl;
            return -1;
        }

        return head->data;
    }
    bool empty()
    {
        return head == NULL;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}