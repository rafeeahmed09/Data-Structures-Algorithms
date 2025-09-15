#include <iostream>
#include <queue>
#include <list>
#include <vector>
using namespace std;
class graph
{
    int v;
    list<int> *l;

public:
    graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void BFS()
    { // Breadth First Search
        queue<int> q;
        vector<bool> vis(v, false);
        q.push(0);
        vis[0] = true;
        while (q.size() > 0)
        {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for (int v : l[u])
            {
                if (!vis[v])
                {
                    q.push(v); // enqueue
                    vis[v] = true; // mark as visited
                }
            }
        }
    }
};

int main()
{
    graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.BFS();

    return 0;
    
    
}