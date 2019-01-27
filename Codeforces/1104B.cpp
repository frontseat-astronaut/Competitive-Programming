#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int main()
{
    string s;
    cin>>s;
    int i=0, n=s.size();
    vector<pair<char,int>>v;
    while(i<n)
    {
        char ch=s[i];
        int cnt=0;
        while(i<n && ch==s[i])
        {
            i++;
            cnt++;
        }
        v.push_back({ch, cnt});
    }
    n=v.size();
    stack<char>st;
    int cnt=0;
    for(int i=0; i<n; ++i)
    {
        if(v[i].ss&1)
        {
            if(!st.empty() && st.top()==v[i].ff)
            {
                cnt++;
                st.pop();
            }
            else
                st.push(v[i].ff);
        }
        cnt+=v[i].ss/2;
    }
    if(cnt&1)
    {
        cout<<"Yes";
    }
    else cout<<"No";
}