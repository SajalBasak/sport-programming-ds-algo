#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int> > adjLists;

public:
    void addEdge(int x, int y)
    {
        adjLists[x].push_back(y);
        adjLists[y].push_back(x);
    }

    void dfs_helper(int src, map<int, bool>&isVisited)
    {
        cout<<src<<" ";
        isVisited[src]=true;

        list<int>::iterator it;
        for(it=adjLists[src].begin();it!=adjLists[src].end();it++)
        {
            if(!isVisited[*it])
            {
                dfs_helper(*it, isVisited);
            }
        }
    }

    void dfs(int src)
    {
        map<int, bool>isVisited;

        list<int>:: iterator i;
        for(i=adjLists[src].begin();i!=adjLists[src].end();i++)
        {
            isVisited[*i]=false;
        }
        dfs_helper(src, isVisited);
    }
};

int main()
{
    Graph g;
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.dfs(0);

    return 0;
}
