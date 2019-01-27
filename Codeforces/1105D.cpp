#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second

int n, m;
char g[1000][1000];
int p;
int s[10], ans[10];
pii d[4]={
    {0,1}, {1, 0}, {-1, 0}, {0, -1}
};
int cnt=0;
int rnd=0;
queue <pair<int, pii>> q[10];
void bfs(int pl)
{
    while(!q[pl].empty())
    {
        pii x=q[pl].front().ss;
        int dist=q[pl].front().ff;
        if(dist==(rnd+1)*s[pl])
        {
            break;
        }
        q[pl].pop();
        
        for(auto del:d)
        {
            if(x.ff+del.ff>=n || x.ff+del.ff<0 || x.ss+del.ss>=m || x.ss+del.ss<0)
                continue;
            if(g[x.ff+del.ff][x.ss+del.ss]=='.')
            {
                g[x.ff+del.ff][x.ss+del.ss]=pl+'0';
                cnt--;
                q[pl].push({dist+1, {x.ff+del.ff, x.ss+del.ss}});
            }
        }
    }
}

void display()
{
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            cout<<g[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m>>p;
    for(int i=0; i<p; ++i)
    {
        cin>>s[i+1];
    }
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            cin>>g[i][j];
            if(g[i][j]!='.' && g[i][j]!='#')
            {
                q[g[i][j]-'0'].push({0,{i,j}});
            }   
            if(g[i][j]=='.') cnt++;
        }       
    }
    int i=1;
    // display();
    int streak=0;
    while(cnt>0)
    {
        int init=cnt;
        bfs(i);
        if(cnt==init)
            streak++;
        else
            streak=0;
        // display();
        i=i%p+1;
        if(i==1)
            rnd++;
        if(streak==p)
            break;
    }
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            if(g[i][j]!='.' && g[i][j]!='#')
            {
                ans[g[i][j]-'0']++;
            }   
        }
    }
    for(int i=1; i<=p; ++i)
        cout<<ans[i]<<' ';
}