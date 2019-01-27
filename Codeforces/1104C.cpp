#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    bool g[4][4]={};
    for(auto x:s)
    {
        if(x=='1')
        {
            for(int i=0; i<4; ++i)
            {
                int cnt=0;
                int j;
                for(j=0; j<3; ++j)
                {
                    if(!g[i][j] && !g[i][j+1]) break;
                }
                if(j<3)
                {
                    cout<<i+1<<" "<<j+1<<endl;
                    g[i][j]=1; g[i][j+1]=1;
                    break;
                }
            }
            for(int i=0; i<4; ++i)
            {
                bool all=1;
                int j;
                for(j=0; j<4; ++j)
                {
                    if(!g[i][j])
                    {
                        all=0;
                        break;
                    }
                }
                if(all)
                {
                    for(int j=0; j<4; ++j)
                        g[i][j]=0;
                }
            }
        }
        else
        {
            for(int i=0; i<4; ++i)
            {
                int cnt=0;
                int j;
                for(j=0; j<3; ++j)
                {
                    if(!g[j][i] && !g[j+1][i]) break;
                }
                if(j<3)
                {
                    cout<<j+1<<" "<<i+1<<endl;
                    g[j][i]=1; g[j+1][i]=1;
                    break;
                }
            }
            for(int i=0; i<4; ++i)
            {
                bool all=1;
                for(int j=0; j<4; ++j)
                {
                    if(!g[j][i])
                    {
                        all=0;
                        break;
                    }
                }
                if(all)
                {
                    for(int j=0; j<4; ++j)
                        g[j][i]=0;
                }
            }
        }
    }
}