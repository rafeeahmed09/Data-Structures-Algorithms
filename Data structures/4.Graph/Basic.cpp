#include <iostream>
#include <vector>
#include <list>
using namespace std;

class graph // undirected graph
{
    int v;
    list<int> *l;

public:
    graph(int v) // constructor
    {
        this->v = v;
        l = new list<int>[v];
    }
    void addEdge(int x, int y)
    { // add edge between x and y.
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void printAdvlist() // print adjacency list.
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << ":";
            for (int neigh : l[i])
            {
                cout << neigh << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 3);

    g.printAdvlist();

    return 0;
}