#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

class Graph
{
    map<int, list<int> > adjLists;

public:
    void addEdge(int src, int dest)
    {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src);
    }

    void bfs(int vertex)
    {
        map<int, bool>isVisited;
        queue<int> q;

        q.push(vertex);
        isVisited[vertex]=true;

        while(!q.empty())
        {
            int top=q.front();
            q.pop();

            cout<<top<<" ";

            list<int>::iterator it;
            for(it=adjLists[top].begin();it!=adjLists[top].end();it++)
            {
                if(!isVisited[*it])
                {
                    q.push(*it);
                    isVisited[*it]=true;
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
