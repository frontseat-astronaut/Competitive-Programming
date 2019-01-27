#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
struct tariff
{
    int l, r;
    int c, p;
    bool operator<(tariff const &o) const
    {
        return p<o.p;
    }
};
struct marker
{
    int x, idx;
    int se;
    bool operator<(marker const &o) const
    {
        if(x!=o.x)
            return x<o.x;
        return se<o.se;
    }
};

const int M=1e6+1;
int n, k, m;
tariff tar[M];
vector<marker>X;
pii bit[M];

void add(int idx, pii p)
{
    while(idx<m)
    {
        bit[idx].ff+=p.ff;
        bit[idx].ss+=p.ss;
        idx=idx|(idx+1);
    }
}
pii sum(int r)
{
    pii ret={0,0};
    for(; r>=0; r=(r&(r+1))-1)
    {
        ret.ff+=bit[r].ff;
        ret.ss+=bit[r].ss;
    }
    return ret;
}

int32_t main()
{
    cin>>n>>k>>m;
    for(int i=0; i<m; ++i)
    {
        cin>>tar[i].l>>tar[i].r>>tar[i].c>>tar[i].p;
    }
    sort(tar, tar+m);
    for(int i=0; i<m; ++i)
    {
        X.push_back({tar[i].l, i, 0});
        X.push_back({tar[i].r, i, 1}); 
    }
    sort(X.begin(), X.end());

    int curr=1, id=0;
    int ans=0;
    while(curr<=n)
    {
        while(id<2*m && X[id].x==curr && X[id].se==0)
        {
            add(X[id].idx, {tar[ X[id].idx ].c, tar[ X[id].idx ].c * tar[ X[id].idx ].p});
            id++;
        }
        //binary search

        // for(int i=0; i<m; ++i)
        //     cout<<sum(i).ff<<':'<<sum(i).ss<<" ";
        // cout<<"\n";

        pii tmp;
        int l=0, r=m-1, mid;
        while(l<=r)
        {
            mid=(l+r)>>1;
            tmp=sum(mid);
            if(tmp.ff<k)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        if(tmp.ff<k && mid!=m-1)
        {
            mid++;
            tmp=sum(mid);
        }
        ans+=tmp.ss-(max((int)0,tmp.ff-k))*tar[ mid ].p;
        while(id<2*m && X[id].x==curr && X[id].se==1)
        {
            add(X[id].idx, {-tar[ X[id].idx ].c, -tar[ X[id].idx ].c * tar[ X[id].idx ].p});
            id++;
        } 
        curr++;
    }
    cout<<ans;
}