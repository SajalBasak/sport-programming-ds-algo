#include<bits/stdc++.h>
using namespace std;

class Graph
{
    unordered_map<int, list<pair<int, int> > >adjLists;

public:
    void addEdge(int x, int y, int dist, bool biDir = true)
    {
        adjLists[x].push_back(make_pair(y, dist));

        if(biDir)
        {
            adjLists[y].push_back(make_pair(x, dist));
        }
    }

    void printGraph()
    {
        // unordered_map<int, list<pair<int, int> > >::iterator i;
        // for(i=adjLists.begin();i!=adjLists.end();i++)
        // {
        //     cout<<i->first<<" ";
        //     list<pair<int, int> >::iterator j;
        //     for(j=(i->second).begin();j!=(i->second).end();j++)
        //     {
        //         cout<<"("<<j->first<<","<<j->second<<")";
        //     }
        //     cout<<endl;
        // }

        for(auto i:adjLists)
        {
            cout<<i.first<<"-> ";
            for(auto j:i.second)
            {
                cout<<"("<<j.first<<","<<j.second<<")";
            }
            cout<<endl;
        }
    }

    void dijkstra(int src)
    {
        unordered_map<int, int>dist;

        for(auto i:adjLists)
        {
            dist[i.first]=INT_MAX;
        }

        set<pair<int, int> >s;
        dist[src]=0;
        s.insert(make_pair(0,src));

        while(!s.empty())
        {
            auto top = *(s.begin());
            s.erase(s.begin());

            for(auto i:adjLists[top.second])
            {
                if(dist[top.second]+i.second<dist[i.first])
                {
                    s.erase(make_pair(dist[i.first],i.first));
                    dist[i.first]=dist[top.second]+i.second;
                    s.insert(make_pair(dist[i.first],i.first));
                }
            }
        }

        for(auto i:dist)
        {
            cout<<"Distance of "<<i.first<<" from "<<src<<" is: "<<(i.second == INT_MAX ? -1 : i.second)<<endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(0,3,2);
    g.addEdge(1,2,3);
    g.addEdge(2,3,2);
    g.addEdge(3,4,4);
    g.addEdge(4,5,4);

    g.printGraph();

    g.dijkstra(0);

    return 0;
}
