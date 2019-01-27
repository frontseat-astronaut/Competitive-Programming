#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=2e5+1;
int ans=0;
struct edge
{
    int u, v, w;
    bool operator<(edge const &o) const{
        return w<o.w;
    }
} ;
vector<edge>e;
int parent[N];
int find_set(int x)
{
    if(x==parent[x])
        return x;
    return parent[x]=find_set(parent[x]);
}
void union_set(int a, int b)
{
    a=find_set(a);
    b=find_set(b);
    if(a!=b)
    {
        if(rand()&1)
        {
            swap(a, b);
        }
        parent[a]=b;
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(time(0));
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; ++i)
    {
        int u, v, w;
        cin>>u>>v>>w;
        e.push_back({u, v, w});
    }
    sort(e.begin(), e.end());

    for(int i=1; i<=n; ++i)
    {
        parent[i]=i;
    }
    // for(auto ed: e)
    //     cout<<ed.u<<' '<<ed.v<<' '<<ed.w<<'\n';
    int i=0, u, v, s, t;
    while(i<m)
    {
        int cst=e[i].w;
        vector<edge>use;
        while(i<m && e[i].w==cst)
        {
            u=find_set(e[i].u), v=find_set(e[i].v);
            if(u!=v)
            {
                use.push_back({u, v, cst});
            }
            ++i;
        }
        for(auto ed: use)
        {
            u=find_set(ed.u), v=find_set(ed.v);
            if(u==v) ans++;
            else union_set(u, v);
        }
    }
    cout<<ans<<endl;
}