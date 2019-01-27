#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n;++i)
        cin>>a[i];
    string s;
    cin>>s;
    int i=0; 
    int ans=0;
    while(i<n)
    {
        char ch=s[i];
        multiset<int>st;
        while(i<n && ch==s[i])
        {
            st.insert(a[i]);
            i++;
        }
        int l=0;
        for(auto itr=st.rbegin(); itr!=st.rend() && l<k; ++itr, ++l)
        {
            ans+=(*itr);
        }
    }
    cout<<ans;
}