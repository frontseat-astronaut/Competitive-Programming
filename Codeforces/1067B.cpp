#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+1;
int n, k;
vector<int>adj[N];
bool ans=1;
int root, maxd=0;

void find_root(int x, int e, int dist, int kth)
{
    if(dist==k)
        kth=x;
    if(adj[x].size()==1)
    {
        if(dist>maxd)
        {
            maxd=dist;
            root=kth;
        }
        return;
    }
    for(auto y:adj[x])
    {
        if(y!=e)
        {
            find_root(y, x, dist+1, kth);
        }
    }
}

void dfs(int x, int e, int dist)
{
    if(adj[x].size()==1)
    {
        if(dist!=k)
        {
            ans=0;
        }
        return;
    }
    int deg=0;
    for(auto y: adj[x])
        if(y!=e)
        {
            dfs(y, x, dist+1);
            deg++;
        }
    if(deg<3)
    {
        ans=0;
    }
}

int32_t main()
{
    cin>>n>>k;
    for(int i=0; i<n-1; ++i)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int leaf=0;
    for(int i=1; i<=n; ++i)
    {
        if(adj[i].size()==1)
            leaf=i;
    }
    if(!leaf) ans=0;
    find_root(leaf, 0, 0);
    if(!root)
    {
        cout<<"No";
        exit(0);
    }
    dfs(root, 0, 0);
    if(ans)
        cout<<"Yes";
    else cout<<"No";
}