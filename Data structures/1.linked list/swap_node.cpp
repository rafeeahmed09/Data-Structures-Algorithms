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

class linked
{
private:
    node *head;
    node *tail;

public:
    linked()
    {
        head = tail = NULL;
    }

    void push_front(int val){
        node* newnode = new node(val);
        if (head == NULL)
        {
            head = tail = newnode;
        }else{
            newnode->next = head;
            head = newnode;
        }
        
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


    node* swap(node* head){
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        node* prev = NULL;
        node* curr = head;
        node* new_head = head->next;

        while (curr != NULL && curr->next != NULL)
        {
            node* next = curr->next;
            node* next_pair = next->next;

            next->next = curr;
            if (prev != NULL)
                prev->next = next;
            curr->next = next_pair;

            prev = curr;
            curr = next_pair;
        }
        return new_head;
    }

    void swap_pairs() {
        head = swap(head);
    }
};


int main() {
    linked mylist;

    mylist.push_front(1);
    mylist.push_front(2);
    mylist.push_front(3);

    cout << "Original list: ";
    mylist.print();

    mylist.swap_pairs();

    cout << "After swapping pairs: ";
    mylist.print();

    return 0;
}
#include <iostream>
#include <unordered_map>
using namespace std;

// Node class for doubly linked list
class Node {
public:
    int key, value;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

// LRU Cache class
class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache; // maps key -> node
    Node* head; // dummy head
    Node* tail; // dummy tail

    // Helper: remove node from list
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Helper: insert node at front (right after head)
    void insertAtFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(0, 0); // dummy head
        tail = new Node(0, 0); // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1; // not found
        }
        Node* node = cache[key];
        // Move node to front (most recently used)
        removeNode(node);
        insertAtFront(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Update existing node
            Node* node = cache[key];
            node->value = value;
            removeNode(node);
            insertAtFront(node);
        } else {
            if (cache.size() == capacity) {
                // Remove least recently used (node before tail)
                Node* lru = tail->prev;
                removeNode(lru);
                cache.erase(lru->key);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            insertAtFront(newNode);
            cache[key] = newNode;
        }
    }

    // Debug: print cache state
    void display() {
        Node* curr = head->next;
        cout << "Cache state: ";
        while (curr != tail) {
            cout << "[" << curr->key << ":" << curr->value << "] ";
            curr = curr->next;
        }
        cout << endl;
    }
};

// Example usage
int main() {
    LRUCache lru(3);

    lru.put(1, 10);
    lru.put(2, 20);
    lru.put(3, 30);
    lru.display();

    cout << "Get 2 -> " << lru.get(2) << endl;
    lru.display();

    lru.put(4, 40); // evicts 1
    lru.display();

    cout << "Get 1 -> " << lru.get(1) << endl; // should return -1

    return 0;
}
