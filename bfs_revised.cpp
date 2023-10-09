#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int> >adjLists;

public:
    void addEdge(int x, int y)
    {
        adjLists[x].push_back(y);
        adjLists[y].push_back(x);
    }

    void bfs(int src)
    {
        queue<int>q;
        map<int, bool>isVisited;

        q.push(src);
        isVisited[src]=true;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            cout<<node<<" ";

            list<int>:: iterator i;
            for(i=adjLists[node].begin();i!=adjLists[node].end();i++)
            {
                if(!isVisited[*i])
                {
                    q.push(*i);
                    isVisited[*i]=true;
                }
            }
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.bfs(0);

    return 0;
}
