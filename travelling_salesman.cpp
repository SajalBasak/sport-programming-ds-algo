#include<bits/stdc++.h>
using namespace std;

int matrix[15][15];
int minCost=100000, n;

void travellingSalesman(int current, int *isVisited, int cost, int left)
{
    if(left==0)
    {
        cost+=matrix[current][0];
        if(cost<minCost) minCost=cost;
        return;
    }

    for(int i=1;i<n;i++)
    {
        if(isVisited[i]==0)
        {
            isVisited[i]=1;
            travellingSalesman(i,isVisited,cost+matrix[current][i],left-1);
            isVisited[i]=0;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        minCost=100000;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>matrix[i][j];
            }
        }

        int isVisited[15];
        memset(isVisited,0,15*sizeof(int));

        isVisited[0]=1;
        travellingSalesman(0,isVisited,0,n-1);
        cout<<minCost<<endl;
    }

    return 0;
}
