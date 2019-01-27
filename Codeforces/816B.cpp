#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+1;
int bit[N];

void add(int idx, int p)
{
    while(idx<N)
    {
        bit[idx]+=p;
        idx=idx|(idx+1);
    }
}
int sum(int r)
{
    int ret=0;
    for(; r>=0; r=(r&(r+1))-1)
        ret+=bit[r];
    return ret;
}

int32_t main()
{
    int n, k, q;
    cin>>n>>k>>q;
    int L[N]={}, R[N]={}, temp[N]={};
    for(int i=0; i<n; ++i)
    {
        int x, y;
        cin>>x>>y;
        L[x]++;
        R[y]++;
    }
    int sm=0;
    for(int i=1; i<=2e5; ++i)
    {
        sm+=L[i];
        temp[i]=sm;
        sm-=R[i];
        if(temp[i]>=k)
            add(i, 1);
    }
    while(q--)
    {
        int l, r;
        cin>>l>>r;
        int ans=sum(r);
        if(l)
            ans-=sum[l-1];
        cout<<ans<<endl;
    }
}