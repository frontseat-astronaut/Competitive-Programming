#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(n==2)
        {
            if(s[0]>=s[1])
                cout<<"NO\n";
            else
            {
                cout<<"YES\n";
                cout<<2<<"\n"<<s[0]<<' '<<s[1]<<endl;
            }
        }   
        else
        {
            cout<<"YES\n";
            cout<<2<<endl;
            cout<<s[0]<<" ";
            for(int i=1 ;i<n; ++i)
                cout<<s[i];
            cout<<"\n";
        }
    }
}