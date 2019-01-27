#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cnt=0, i=0;
    int x[256]={};
    int ans=0;
    while(i<n)
    {
        // cout<<i<<' ';
        char ch=s[i];
        cnt=0;
        while(i<n && ch==s[i] && cnt<k)
        {
            i++;
            cnt++;
        }
        if(cnt<k)
            continue;
        x[ch]++;
        ans=max(x[ch], ans);
    }
    cout<<ans;
}