#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

class Graph
{
    int v;
    list<string> *l;
    unordered_map<string, int> mp;
    vector<string> names;
    int idx = 0;

public:
    Graph(int v)
    {
        this->v = v; 
        l = new list<string>[v];
    }

    void addEdge(string x, string y){
        if(mp.find(x) == mp.end()){
            mp[x] = idx++;
            names.push_back(x);
        }
        if(mp.find(y) == mp.end()){
            mp[y] = idx++;
            names.push_back(y);
        }
        l[mp[x]].push_back(y);
        l[mp[y]].push_back(x);
    }

    void print(){
        for(int i=0; i<idx; i++){
            cout<<names[i]<<" : ";
            for(const string& neigh : l[i]){
                cout<<neigh<<" ";
            }
            cout << endl;
        }
    }
};

int main(){
    Graph g(10);
    g.addEdge("A", "B");
    g.addEdge("A", "C");
    g.addEdge("B", "D");
    g.print();
    return 0;
}