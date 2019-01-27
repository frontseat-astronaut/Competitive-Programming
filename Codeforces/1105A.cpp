#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; ++i)
    {
        cin>>a[i];
    }
    int minm=LLONG_MAX, ans;
    for(int t=1; t<=105; ++t)
    {
        int sm=0;
        for(int i=0; i<n; ++i)
        {
            if(a[i]==t)
                continue;
            sm+=min(abs(t-1-a[i]), abs(t+1-a[i]));
        }
        if(sm<minm)
        {
            minm=sm;
            ans=t;
        }
    }
    cout<<ans<<" "<<minm;
}