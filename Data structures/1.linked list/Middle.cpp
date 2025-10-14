#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};
class list{
private:
    node* head;
    node* tail;
public:
    list(){
        head = tail = NULL;
    }
    void push_front(int val){
        node* newNode = new node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
        
    }
    void Middle(){
        node* slow = head;
        node* fast = head;
        if (head == NULL)
        {
            cout<<"list is empty"<<endl;
            return;
        }
        while (fast != NULL && fast->next !=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        cout << "Middle element is: " << slow->data << endl;
    
        
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
int main(){
    list mylist;
    mylist.push_front(1);
    mylist.push_front(2);
    mylist.push_front(3);
    mylist.push_front(4);
    mylist.push_front(5);
    mylist.push_front(6);
    mylist.print();
    mylist.Middle();

    return 0;
}