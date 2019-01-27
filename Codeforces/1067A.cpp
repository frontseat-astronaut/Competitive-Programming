#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int m=998244353 ;
int dp[201][2];
int a[200000];
int n, pref, suf;

int32_t main()
{
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        cin>>a[i];
    }

    if(a[n-1]!=-1)
    {
        dp[a[n-1]][1]=1;
    }
    else
    {
        for(int j=1; j<=200; ++j)
            dp[j][1]=1;
    }
    pref=0;
    for(int j=1; j<=200; ++j)
    {
        pref=(pref+dp[j][1])%m;
        dp[j][1]=pref;
        // cout<<dp[j][1]<<' ';
    }
    // cout<<"\n";

    for(int i=n-2; i>=0; --i)
    {
        int tmp[201][2]={};
        if(a[i]!=-1)
        {
            if(a[i]<200)
                tmp[ a[i] ][0]=dp[ a[i]+1 ][0];
            tmp[ a[i] ][0]=( tmp[ a[i] ][0] + dp[ a[i] ][1] )%m;
            if(a[i]>1)
                tmp[ a[i] ][0]=( tmp[ a[i] ][0] - dp[ a[i]-1 ][1] )%m;

            tmp[ a[i] ][1]=( tmp[ a[i] ][0] + dp[ a[i] -1 ][1])%m;            
        }
        else
        {
            for(int j=1; j<=200; ++j)
            {
                if(j<200)
                    tmp[ j ][0]=dp[ j+1 ][0];
                tmp[ j ][0]=( tmp[ j ][0] + dp[ j ][1] )%m;
                if(j>1)
                    tmp[ j ][0]=( tmp[ j ][0] - dp[ j-1 ][1])%m;

                tmp[ j ][1]=( tmp[ j ][0] + dp[ j -1 ][1])%m; 
            }
        }
        pref=0;
        for(int j=1; j<=200; ++j)
        {
            pref=(pref+tmp[j][1])%m;
            dp[j][1]=pref;
            // cout<<tmp[j][1]<<' ';
        }
        // cout<<'\n';
        suf=0;
        for(int j=200; j>0; --j)
        {
            suf=(suf+tmp[j][0])%m;
            dp[j][0]=suf;
            // cout<<tmp[j][0]<<' ';
        }
        // cout<<'\n';
    }

    int ans=0;
    ans=dp[1][0];
    ans=(ans+m)%m;
    cout<<ans;
}