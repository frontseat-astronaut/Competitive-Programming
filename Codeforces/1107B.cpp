#include<bits/stdc++.h>
using namespace std;
#define int long long 
int32_t main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int k, x;
        cin>>k>>x;
        if(x==9) cout<<(9*k)<<endl;
        else cout<<(9*(k-1)+x)<<endl;
    }
}