#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+1;
int n;
vector<int>adj[N];
int dp1[N], cnt[N], dp2[N];

void dfs1(int x, int e)
{
    cnt1[x]=1;
    for(auto y:adj[x])
    {
        if(y!=e)
        {
            dfs1(y, x);
            dp2[x]+=dp1[y];
            dp1[x]+=dp2[y]+cnt[y];
            cnt[x]+=cnt[y];
        }
    }
}

void dfs2(int x, int e)
{
    if(x!=1)
    {
        dp1[x]+= dp2[e]-dp1[x]+(n-cnt[x]);
        dp2[x]+= dp1[e]-dp2[x]-cnt[x];
    }
    for(auto y:adj[x])
    {
        if(y!=e)
            dfs2(y, x);
    }
}

int32_t main()
{
    cin>>n;
    for(int i=0; i<n-1; ++i)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    for(int i=1; i<=n; ++i)
        cout<<dp1[i]<<" ";
    cout<<"\n";
    dfs2(1, 0);
    int ans=0;
    for(int i=1; i<=n; ++i)
        ans+=dp1[i];
    cout<<ans;
}