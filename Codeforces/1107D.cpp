#include<bits/stdc++.h>
using namespace std;
#define int long long
string hex_char_to_bin(char c)
{
    // TODO handle default / error
    switch(toupper(c))
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    bool a[n+1][n+1]={};
    int hx[256];
    for(int i=0; i<n; ++i)
    {  
        string s;
        cin>>s;
        int L=s.length();
        string bin;
        for(int l=0; l<L; ++l)
        {
            string sub=hex_char_to_bin(s[l]);
            bin+=sub;
        }
        bitset<5200>b(bin);
        for(int j=0; j<n; ++j)
            a[i][j]=b[j];
    }
    int minm=n;
    for(int i=0; i<n; ++i)
    {
        int j=0; 
        while(j<n)
        {
            bool val=a[i][j];
            int cnt=0;
            while(j<n && val==a[i][j])
            {
                cnt++;
                j++;
            }
            minm=__gcd(minm, cnt);
        }
    }
    for(int i=0; i<n; ++i)
    {
        int j=0; 
        while(j<n)
        {
            bool val=a[j][i];
            int cnt=0;
            while(j<n && val==a[j][i])
            {
                cnt++;
                j++;
            }
            minm=__gcd(cnt, minm);
        }
    }
    cout<<minm<<endl;
}