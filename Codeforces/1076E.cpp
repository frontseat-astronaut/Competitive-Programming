#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

const int N=300001;
int n, m;

vector<int>adj[N];
int dep[N<<1];
int s[N];
vector<pii> Q[N];

void update(int v, int l, int r)
{
    r++;
    for(l+=n, r+=n; l<r; l>>=1, r>>=1)
    {
        if(l&1)
            dep[l++]+=v;
        if(r&1)
            dep[--r]+=v;
    }
}

int query(int h)
{
    int res=0;
    for (h+=n; h>0; h>>=1)
        res+=dep[h];
    return res;
}

void dfs(int x, int prev, int d)
{
    for(auto q: Q[x])
        update(q.ss, d, min(q.ff+d,n-1));
    s[x]=query(d);
    for(auto y:adj[x])
    {
        if(y!=prev)
            dfs(y,x,d+1);
    }
    for(auto q: Q[x])
        update(-q.ss, d, min(q.ff+d,n-1));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for (int i = 0; i < n-1; ++i)
    {
        int x, y;
        cin>>x>>y;

        adj[x].pb(y);
        adj[y].pb(x);
    }
    cin>>m;
    for (int i = 0; i < m; ++i)
    {
        int v, d, x;
        cin>>v>>d>>x;
        Q[v].pb({d,x});
    }
    dfs(1, 0, 0);
    for(int i=1; i<=n; ++i)
    {
        cout<<s[i]<<" ";
    }
}