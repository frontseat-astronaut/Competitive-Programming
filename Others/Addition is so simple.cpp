#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int n;
    cin>>n;
    int a[n];
    int dp[n+1][n+1]={};
    int sm[n+1]={}, sum=0;
    for(int i=0; i<n; ++i)
    {
        cin>>a[i];
        sum+=a[i];
        sm[i]=sum;
    }
    for(int d=1; d<=n-1; ++d)
    {
        for(int l=0; l<n-d; ++l)
        {
            int r=l+d;
            dp[l][r]=LLONG_MAX;
            for(int k=l+1; k<=r; ++k)
            {
                dp[l][r]=min(dp[l][r], dp[l][k-1]+dp[k][r]);
            }
            dp[l][r]+=sm[r]-sm[l]+a[l];
        }
    }
    cout<<dp[0][n-1]<<endl;
}