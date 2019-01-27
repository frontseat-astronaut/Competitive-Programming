#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int amb[n];
    for(int i=0; i<n; ++i)
        cin>>amb[i];
    
    int adp[4]={}, cdp[4]={};
    if(s[n-1]=='d')
    {
        adp[3]=amb[n-1];
        cdp[3]=1;
    }
    for(int i=n-2; i>=0; --i)
    {
        if(s[i]=='d')
        {
            // cdp[3]++;
            adp[3]+=amb[i];
        }
        if(s[i]=='r')
        {
            // cdp[2]+=cdp[3];
            adp[2]=min(amb[i]+adp[2], adp[3]);
        }
        if(s[i]=='a')
        {
            // cdp[2]+=cdp[3];
            adp[1]=min(amb[i]+adp[1], adp[2]);
        }
        if(s[i]=='h')
        {
            // cdp[2]+=cdp[3];
            adp[0]=min(amb[i]+adp[0], adp[1]);
        }
    }
    cout<<adp[0];
}