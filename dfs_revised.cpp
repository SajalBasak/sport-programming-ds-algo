#include<iostream>
#include<map>
#include<list>
using namespace std;

class Graph
{
    map<int, list<int> >adjLists;
    map<int, bool>isVisited;

public:
    void addEdge(int src, int dest)
    {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src);
    }

    void dfs(int vertex)
    {
        isVisited[vertex]=true;
        cout<<vertex<<" ";

        list<int>::iterator it;
        for(it=adjLists[vertex].begin();it!=adjLists[vertex].end();it++)
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
    Graph g;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,4);

    g.dfs(0);

    return 0;
}
