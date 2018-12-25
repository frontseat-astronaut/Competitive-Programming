#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a, b;
        cin>>a>>b;

        int A=a.length(), B= b.length();
        
        bool dp[A]={};
        bool ans=0;
        int capcnt=0;
        for(int j=0; j<A; ++j)
        {
            if(a[j]==b[0])
            {
                ans=1;
                dp[j]=1;
                j++;
                while(j<A && !isupper(a[j]))
                    dp[j++]=1;
                break;
            }
            else if (toupper(a[j])==b[0])
            {    
                dp[j]=1;
                ans=1;
            }
            else
            {
                dp[j]=dp[j-1];
            }
        }
        // cout<<ans<<' ';
        for(int i=1; i<B; ++i)
        {
            bool tmp[A]={};
            bool poss=0;
            for(int j=1; j<A; ++j)
            {
                if(!dp[j-1])
                    continue;
                if(a[j]==b[i])
                {
                    tmp[j]=1;
                    poss=1;
                }
                else if (toupper(a[j])==b[i])
                {    
                    tmp[j]=1;
                    poss=1;
                }
                else
                {
                    if(isupper(a[j]))
                        tmp[j]=0;
                    else
                    {
                        tmp[j]=tmp[j-1];
                    }
                }
            }
            ans=ans&poss;
            for(int j=0; j<A; ++j)
                dp[j]=tmp[j];
            // cout<<poss<<' ';
        }
        ans=ans&dp[A-1];
        if(ans)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}