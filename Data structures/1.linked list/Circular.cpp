#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class circ
{
private:
    Node *head;
    Node *tail;

public:
    circ()
    {
        head = tail = NULL;
    }

    void InsertAtHead(int val)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = tail = newnode;
            tail->next = head;
        }
        else
        {
            newnode->next = head;
            head = newnode;
            tail->next = head;
        }
    }

    void print()
    {

        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
       do{
           cout<<temp->data<<"->";
           temp = temp->next;
       }while(temp != head);

        cout << "(back to head)" << endl;
    }

    void InsertAtTail(int val)
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = tail = newnode;
            tail->next = head;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
            tail->next = head;
        }
    }

    void deleteATHead()
    {
        
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
         if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }else{
            head = head->next;
            tail->next = head;
            delete temp;
        }
        
    }

    void deleteATTail()
    {
        if (head == NULL)
        {
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *temp = head;
            Node *pre = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            tail = temp;
            tail->next = head;
            temp->next = NULL;

            delete pre;
        }
    }
};
int main()
{
    circ mylist;

    mylist.InsertAtHead(1);
    mylist.InsertAtHead(2);
    mylist.InsertAtHead(3);

    cout<< "AFter inserting at head :";
    mylist.print();
    
    mylist.deleteATHead();
    cout<<"After deleting head : ";
    mylist.print();


    mylist.deleteATTail();
    cout<<"After deleting tail : ";
    mylist.print();

    

    return 0;
}