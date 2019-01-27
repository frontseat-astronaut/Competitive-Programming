#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int,int>
#define ff first
#define ss second
int32_t main()
{
    int n, m;
    cin>>n>>m;
    int a[n];
    for(int i=0; i<n; ++i)
    {
        cin>>a[i];
    }
    pii seg[m];
    for(int i=0; i<m; ++i)
    {
        cin>>seg[i].ff>>seg[i].ss;
        seg[i].ff--, seg[i].ss--;
    }
    int ans=0;
    vector<int>ansseg;
    for(int i=0; i<n; ++i)
    {
        for(int j=i+1; j<n; ++j)
        {
            int d=a[j]-a[i];
            vector<int>tmp;
            for(int k=0; k<m; ++k)
            {
                if((seg[k].ff<=i && seg[k].ss>=i) && (seg[k].ss<j || seg[k].ff>j))
                {
                    d++;
                    tmp.push_back(k);
                }
            }
            if(ans<d)
            {
                ans=d;
                ansseg=tmp;
            }
            d=a[i]-a[j];
            tmp.clear();
            for(int k=0; k<m; ++k)
            {
                if((seg[k].ff<=j && seg[k].ss>=j) && (seg[k].ss<i || seg[k].ff>i))
                {
                    d++;
                    tmp.push_back(k);
                }
            }
            if(ans<d)
            {
                ans=d;
                ansseg=tmp;
            }
        }
    }
    cout<<ans<<"\n";
    cout<<ansseg.size()<<"\n";
    for(auto s: ansseg)
        cout<<s+1<<' ';
}