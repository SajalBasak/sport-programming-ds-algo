#include<iostream>
#include<algorithm>
using namespace std;

int coinChange(int arr[],int n, int m)
{


    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=n+1;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if((i-arr[j])>=0)
            {
                dp[i]=min(dp[i],1+dp[i-arr[j]]);
            }
        }
    }

    if(dp[n]!=(n+1)) return dp[n];
    return -1;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int x;
    cin>>x;
    cout<<coinChange(arr,x,n)<<endl;

    return 0;
}
