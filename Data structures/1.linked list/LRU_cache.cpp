#include <iostream>
#include <unordered_map>

using namespace std;

class node {
public:
    int key;
    int val;
    node *next;
    node *prev;

    node(int k, int v) {
        key = k;
        val = v;
        next = prev = NULL;
    }
};

class LRUcache {
    unordered_map<int, node *> mp;
    node *head = new node(-1, -1); // Dummy head
    node *tail = new node(-1, -1); // Dummy tail
    int limit;

public:
    void addnode(node *newnode) {
        // Add a new node right after the head
        node *oldnode = head->next;
        head->next = newnode;
        newnode->prev = head;
        newnode->next = oldnode;
        oldnode->prev = newnode;
    }

    void delnode(node *oldnode) {
        // Delete a node from the list
        node *oldprev = oldnode->prev;
        node *oldnext = oldnode->next;
        
        oldprev->next = oldnext;
        oldnext->prev = oldprev;
    }

    LRUcache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // Destructor to clean up memory
    ~LRUcache() {
        node* current = head;
        while (current != nullptr) {
            node* next = current->next;
            delete current;
            current = next;
        }
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        
        node *ansNode = mp[key];
        int ans = ansNode->val;

        // Move to front (most recently used)
        delnode(ansNode);
        addnode(ansNode);

        return ans;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // Key exists, update value and move to front
            node *oldnode = mp[key];
            oldnode->val = value;  // Update the value
            delnode(oldnode);
            addnode(oldnode);
            return;
        }

        // Check if we need to evict
        if ((int)mp.size() == limit) {
            node *lru = tail->prev;
            mp.erase(lru->key);
            delnode(lru);
            delete lru;  // Free memory
        }

        // Add new node
        node *newnode = new node(key, value);
        addnode(newnode);
        mp[key] = newnode;
    }

    void print() {
        
        node* temp = head->next;
        while (temp != tail) {
            cout << "[" << temp->key << ":" << temp->val << "] ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    LRUcache lru(2);
    
    lru.put(1,1);
    lru.put(2,2);
    lru.get(1);
    lru.put(3,3);
    lru.get(2);
    lru.put(4,4);
    lru.get(1);
    lru.get(3);
    lru.get(4);
    lru.print();
   
    cout << "Final state: "; lru.print();


    return 0;
}