#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int,int>
#define ff first
#define ss second
const int one=1;
const int N=1e5+one, M=41; 
int adjm[M][M];
int n, m;

vector<int>clique(one<<(M>>one));
int dp[one<<(M>>one)]={};
int check(int msk)
{
    int cnt=0;
    for(int i=0; i<m; ++i)
    {
        if(msk&((int)one<<i))
        {
            // cout<<i<<" ";
            cnt++;
            for(int j=i+one; j<m; ++j)
            {
                if(!(msk&((int)one<<j))) continue;
                if(!adjm[i][j]) return 0;
            }
        }        
    }
    // cout<<msk<<" "<<cnt<<endl;
    return cnt;
}

bool issubmask(int sub, int sup)
{
    for(int i=0; i<m; ++i)
    {
        if((sub&(one<<i)) && !(sup&(one<<i)))
            return 0;
    }
    return one;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    unordered_map<string,int> ni;
    set<int>fr;
    int k=0;
    for(int i=0; i<n; ++i)
    {
        int q;
        cin>>q;
        if(q==one)
        {
            fr.clear();
        }
        else
        {
            string s;
            cin>>s;
            if(ni.find(s)==ni.end())
            {
                ni[s]=k++;
            }
            int ind=ni[s];
            if(fr.find(ind)!=fr.end()) continue;
            for(auto x:fr)
            {
                adjm[x][ind]=one;
                adjm[ind][x]=one;
            }
            fr.insert(ind);
        }
    }
    int nbr[m]={};
    for(int i=0; i<m; ++i)
    {
        nbr[i]=0;
        for(int j=0; j<m; ++j)
        {
            adjm[i][j]=!adjm[i][j];
            if(!adjm[i][j]) continue;
            if(j<(m>>one))
                nbr[i]|=one<<j;
        }
    }

    int maxm=0;
    for(int i=0; i<(one<<(m>>one)); ++i)
    {
        dp[i]=check(i);
        // cout<<i<<" "<<dp[i]<<endl;
        maxm=max(maxm, dp[i]);
        for(int j=0; j<(m>>one); ++j)
        {
            if(i&(one<<j))
            {
                dp[i]=max(dp[i], dp[ i&(~(one<<j)) ]);
            }
        }
    }
    for(int i=0; i<(one<<m); i+=(one<<(m>>one)))
    {
        clique[i/(one<<(m>>one))]=check(i);
        maxm=max(maxm, clique[i/(one<<(m>>one))]);
    }
    for(int i=0; i<(one<<m); i+=one<<(m>>one))
    {
        int chck=clique[i/(one<<(m>>one))];
        if(chck)
        {
            // cout<<i<<" ";
            int msk=one<<(m>>one);
            msk--;
            for(int vi=m>>one; vi<m; ++vi)
            {
                if(i&(one<<vi))
                {
                    msk=msk&nbr[vi];
                }
            }
            maxm=max(maxm, chck+dp[msk]);
            // cout<<chck+dp[msk]<<endl;
        }
    }
    cout<<maxm;
}