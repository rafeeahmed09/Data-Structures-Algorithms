#include <iostream>
#include <list>
#include <vector>
using namespace std;
class Graph
{
    int v;
    list<int> *l;

public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }


    void DFS(int start, vector<bool> &vis){
        cout<<start<<" ";
        vis[start] = true;
        for(int v : l [start]){
            if (!vis[v])
            {
                DFS(v,vis);
            }
            
        }
    }

    void DFS_Helper(){
        int start = 0;
        vector<bool> vis(v,false);
        DFS(start, vis);
    }
};

int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(1,3);
    g.DFS_Helper();

    return 0;

}