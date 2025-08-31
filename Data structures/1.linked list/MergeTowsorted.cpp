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
class list
{
private:
    node *head;
    node *tail;

public:
    list()
    {
        head = tail = NULL;
    }

    void push_front(int val)
    {
        node *newnode = new node(val);
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }

    void print()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
     static node* mergeNodes(node* h1, node* h2) {
        if (!h1) return h2;
        if (!h2) return h1;

        if (h1->data <= h2->data) {
            h1->next = mergeNodes(h1->next, h2);
            return h1;
        } else {
            h2->next = mergeNodes(h1, h2->next);
            return h2;
        }
    }

    // Merge two sorted lists into *this
    void merge(list &l1, list &l2) {
        head = mergeNodes(l1.head, l2.head);
    }
};
int main()
{
    list list1, list2;

    // First sorted lisnked list.
    list1.push_front(1);
    list1.push_front(3);
    list1.push_front(5);

    // second sorted linked list.
    list2.push_front(2);
    list2.push_front(4);
    list2.push_front(6);

    cout << "list 1:";
    list1.print();

    cout << "list 2:";
    list2.print();

    list mergedlist;
    mergedlist.merge(list1, list2); 
    cout << "merged list :";
    mergedlist.print();

    return 0;
}