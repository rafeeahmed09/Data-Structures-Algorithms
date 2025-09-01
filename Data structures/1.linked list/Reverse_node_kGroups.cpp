#include <iostream>
#include <list>
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

class LinkedList
{
private:
    node *head;
    node *tail;
public:
    node* getHead() { return head; }
    void setHead(node* h) { head = h; }

public:
    LinkedList()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        node *newnode = new node(val);
        if (head == NULL)
        {
            head = tail =   newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }

    node *ReverseK(node *head, int k)
    {
        node *temp = head;
        int count = 0;
        while (count < k)
        {
            if (temp == NULL)
            {
                return head;
            }
            temp = temp->next;
            count++;
        }

        node *prenode = ReverseK(temp, k);

        temp = head;
        count = 0;
        while (count < k)
        {
            node *next = temp->next;
            temp->next = prenode;

            prenode = temp;
            temp = next;
            count++;
        }

        return prenode;
    }

    void print(){
        node* temp = head;
        while (temp != NULL)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        
        cout<<"NULL"<<endl;
    }
};
int main() {
    LinkedList mylist;

    mylist.push_front(1);
    mylist.push_front(2);
    mylist.push_front(3);
    mylist.push_front(4);
    mylist.push_front(5);
    mylist.push_front(6);
    mylist.push_front(7);
    mylist.push_front(8);

    int k = 3;
    node* new_head = mylist.ReverseK(mylist.getHead(), k);
    mylist.setHead(new_head);
    mylist.print();

    return 0;
}