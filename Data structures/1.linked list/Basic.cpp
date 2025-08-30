#include <iostream>
using namespace std;

class node
{
public:
    // node class to represent each element in the linked list.
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class list
{
    // linked list class to manage nodes
private:
    node *head;
    node *tail;

public:
    list() // constructor to initialize head and tail.
    {
        head = tail = NULL;
    }
    void push_front(int val) // fuction to push a node at the front of th list.
    {
        node *newNode = new node(val);
        if (head == NULL) // if the list is empty
        {
            head = tail = newNode;
        }
        else // if the list is not empty
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void push_back(int val) // function to push a node at the back of the list.
    {
        node *newnode = new node(val);
        if (head == NULL)
        { // if the list is empty
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }

    // print

    void print()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl; // Added a NULL to the end for a cleaner output
    }
    void pop_front() // function to removr the frist node of the list.
    {
        if (head == NULL) // if the list is empty
        {
            cout << "linked list is empty" << endl;
            return;
        }
        node *temp = head; // store the head node in a temporary variable.
        head = head->next; // move the head to the next node.
        temp->next = NULL; // set the next of the temporary node to NULL.
        delete temp;       // delete the temporary node.
    }
    void pop_back() // function to remove the last node of the linked list.
    {
        if (head == NULL) // if the list is empty
        {
            cout << "linked list is empty" << endl;
            return;
        }
        node *temp = head;         // store the head node in a temporary variable.
        while (temp->next != tail) // traverse the list until the second last node.
        {
            temp = temp->next; // move to the next node.
        }
        temp->next = NULL; // set the next of the second last node to NULL.
        delete tail;       //  delete the last node.
        tail = temp;       // set the tail to the second last node.
    }
    void Insert(int val, int pos) // function to insert a node at a specific position.
    {
        if (pos < 0) // if the position is negative
        {
            cout << "Invalid postion" << endl;
            return;
        }
        if (pos == 0)
        {
            push_front(val);
            return;
        }
        node *temp = head;
        ;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        node *newnode = new node(val);
        newnode->next = temp->next;
        temp->next = newnode;
    }
    int search(int key)
    {
        node *temp = head;
        int idx = 0;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return idx;
            }

            temp = temp->next;
            idx++;
        }

        return -1;
    }
};
int main()
{   

    list mylist;
    // Initially the list is empty
    cout << "Initial list:" << endl;
    mylist.print();

    cout << "\nPushing 1 to the front:" << endl;
    mylist.push_front(1);
    mylist.print();

    cout << "\nPushing 2 to the back:" << endl;
    mylist.push_back(2);
    mylist.print();

    cout << "\nPushing 3 to the back:" << endl;
    mylist.push_back(3);
    mylist.print();

    cout << "\nIndex of 3 is: " << mylist.search(3) << endl;

    cout << "\nInserting 5 at position 1:" << endl;
    mylist.Insert(5, 1);
    mylist.print();

    cout << "\nPopping from the front:" << endl;
    mylist.pop_front();
    mylist.print();

    cout << "\nPopping from the back:" << endl;
    mylist.pop_back();
    mylist.print();

    
    return 0;
}