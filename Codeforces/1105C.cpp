#include<bits/stdc++.h>
using namespace std;
#define int long long
const int m=1e9+7;
int32_t main()
{
    int n, l, r;
    cin>>n>>l>>r;
    int d=r-l+1;
    l=l%3;
    r=r%3;
    int dp[n+1][3]={};
    int num[3];
    if(l==r)
    {
        num[0]=num[1]=num[2]=(d-1)/3;
        num[l]++;
    }
    else if((r-l+3)%3==1)
    {
        num[0]=num[1]=num[2]=max((int)0, (d-2)/3);
        num[l]++;
        num[r]++;
    }
    else 
    {
        num[0]=num[1]=num[2]=d/3;
    }
    for(int j=0; j<3; ++j)
    {
        dp[0][j]=num[j];
    }
    for(int i=1; i<n; ++i)
    {
        for(int j=0; j<3; ++j)
        {
            for(int k=0; k<3; ++k)
            {
                dp[i][j]=(dp[i][j] + (num[k]*dp[i-1][(j-k+3)%3])%m )%m;
            }
        }
    }
    cout<<dp[n-1][0];
}