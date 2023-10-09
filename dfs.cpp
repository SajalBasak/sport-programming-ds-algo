#include<iostream>
#include<list>
using namespace std;

class graph
{
    int numVertices;
    list<int> *adjLists;
    bool *isVisited;

public:
    graph(int vertices)
    {
        numVertices=vertices;
        adjLists=new list<int>[vertices];
        isVisited=new bool[vertices];
    }

    void addEdges(int src, int dest)
    {
        adjLists[src].push_back(dest);
    }

    void dfs(int vertex)
    {
        isVisited[vertex]=true;
        list<int>adjList=adjLists[vertex];
        cout<<vertex<<" ";
        list<int>::iterator it;
        for(it=adjList.begin();it!=adjList.end();it++)
        {
            if(!isVisited[*it])
            {
                dfs(*it);
            }
        }
    }
};

int main()
{
    graph g(4);
    g.addEdges(0, 1);
    g.addEdges(0, 2);
    g.addEdges(1, 2);
    g.addEdges(2, 3);

    g.dfs(0);

    return 0;
}
