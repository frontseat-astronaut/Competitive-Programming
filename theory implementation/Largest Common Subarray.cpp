#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define ff first
#define ss second
#define int long long

int dp[3001][3001];
pii nxt[3001][3001];
bool taken[3001][3001];
int n, m;
string s, t;

int32_t main()
{
    cin>>s>>t;
    n=s.length();
    m=t.length();
    
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            if(s[i-1]!=t[j-1])
            {
                if(dp[i-1][j]<dp[i][j-1])
                {
                    dp[i][j]=dp[i][j-1];
                    nxt[i][j]={i, j-1};
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                    nxt[i][j]={i-1, j};
                }
            }
            else
            {
                dp[i][j]=dp[i-1][j-1]+1;
                nxt[i][j]={i-1, j-1};
                taken[i][j]=1;
            }
        }
    }
    // cout<<dp[n][m]<<"\n";
    string ans;
    int i=n, j=m;
    while(1)
    {
        if(taken[i][j])
            ans+=s[i-1];
        if(i==0 || j==0)
            break;
        tie(i, j)=nxt[i][j];
    }
    reverse(ans.begin(), ans.end());
    cout<<ans;
}
