#include<bits/stdc++.h>
using namespace std;

int n,m,k, ans=0, arr[20][20];

void flipColumn(int j)
{
    for(int i=0;i<n;i++)
    {
        arr[i][j] == 1 ? arr[i][j] = 0 : arr[i][j] = 1;
    }
}

void helper(int k_rev)
{
    if(k_rev==0)
    {
        int tempAns=0;
        for(int i=0;i<n;i++)
        {
            int flag=0;
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                tempAns++;
            }
        }
        ans=max(ans,tempAns);
        return;
    }

    for(int i=0;i<m;i++)
    {
        flipColumn(i);
        helper(k_rev-1);
        flipColumn(i);
    }
}

int main()
{
    cin>>n>>m>>k;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    helper(k);
    cout<<ans<<endl;

    return 0;
}
