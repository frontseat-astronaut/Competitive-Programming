#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define ff first
#define ss second
#define EPS 1.0e-6

int n, m, k, l;
char a[21][21];
pii tunnel[21][21];
pii start;
map<pii,int>ind;

vector<double>ans(401, 0);
vector< vector<double> > A(401, vector<double>(402, 0));
int N, M;

bool visited[21][21]={};
void dfs(pii x)
{
    if(visited[x.ff][x.ss])
        return;
    visited[x.ff][x.ss]=1;
    ind[x]=l++;
    if(a[x.ff][x.ss]=='%'||a[x.ff][x.ss]=='*')
    {
        return;
    }

    pii tmp={x.ff-1, x.ss};
    if(tmp.ff>0 && tmp.ff<=n && tmp.ss>0 && tmp.ss<=m && a[tmp.ff][tmp.ss]!='#')
    {
        if(tunnel[tmp.ff][tmp.ss].ff)
        {
            dfs(tunnel[tmp.ff][tmp.ss]);
        }
        else
            dfs(tmp);
    }
    tmp={x.ff, x.ss-1};
    if(tmp.ff>0 && tmp.ff<=n && tmp.ss>0 && tmp.ss<=m && a[tmp.ff][tmp.ss]!='#')
    {
        if(tunnel[tmp.ff][tmp.ss].ff)
        {
            dfs(tunnel[tmp.ff][tmp.ss]);
        }
        else
            dfs(tmp);
    }
    tmp={x.ff+1, x.ss};
    if(tmp.ff>0 && tmp.ff<=n && tmp.ss>0 && tmp.ss<=m && a[tmp.ff][tmp.ss]!='#')
    {
        if(tunnel[tmp.ff][tmp.ss].ff)
        {
            dfs(tunnel[tmp.ff][tmp.ss]);
        }
        else
            dfs(tmp);
    }
    tmp={x.ff, x.ss+1};
    if(tmp.ff>0 && tmp.ff<=n && tmp.ss>0 && tmp.ss<=m && a[tmp.ff][tmp.ss]!='#')
    {
        if(tunnel[tmp.ff][tmp.ss].ff)
        {
            dfs(tunnel[tmp.ff][tmp.ss]);
        }
        else
            dfs(tmp);
    }
}

int gauss()
{
    int n = l;
    int m = l;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (A[i][col]) > abs (A[sel][col]))
                sel = i;
        if (abs (A[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (A[sel][i], A[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = A[i][col] / A[row][col];
                for (int j=col; j<=m; ++j)
                    A[i][j] -= A[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = A[where[i]][m] / A[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * A[i][j];
        if (abs (sum - A[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return LLONG_MAX;
    return 1;
}

int32_t main()
{
    cin>>n>>m>>k;

    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            cin>>a[i][j];
            if(a[i][j]=='A')
            {
                start={i,j};
            }
        }
    }
    for(int i=0; i<k; ++i)
    {
        pii u, v;
        cin>>u.ff>>u.ss>>v.ff>>v.ss;
        tunnel[u.ff][u.ss]=v;
        tunnel[v.ff][v.ss]=u;
    }
    dfs(start);
    // cout<<l<<"\n";
    for(auto y: ind)
    {
        int cnt=0;
        pii x=y.ff;
        // cout<<x.ff<<" "<<x.ss<<"\n";
        if(a[x.ff][x.ss]=='%')
        {
            A[y.ss][y.ss]=1;
            A[y.ss][l]=1;
            continue;
        }
        if(a[x.ff][x.ss]=='*')
        {
            A[y.ss][y.ss]=1;
            continue;
        }
        pii tmp={x.ff, x.ss+1};
        if(tmp.ff>0 && tmp.ff<=n && tmp.ss>0 && tmp.ss<=m && a[tmp.ff][tmp.ss]!='#')
         {
            cnt++;
            if(tunnel[tmp.ff][tmp.ss].ff)
            {
                A[ y.ss ] [ ind[tunnel[tmp.ff][tmp.ss]] ]=-1;
            }
            else
                A[y.ss][ ind[tmp] ]=-1;
         }
        tmp={x.ff, x.ss-1};
        if(tmp.ff>0 && tmp.ff<=n && tmp.ss>0 && tmp.ss<=m && a[tmp.ff][tmp.ss]!='#')
         {
            cnt++;
            if(tunnel[tmp.ff][tmp.ss].ff)
            {
                A[ y.ss ] [ ind[tunnel[tmp.ff][tmp.ss]] ]=-1;
            }
            else
                A[y.ss][ ind[tmp] ]=-1;
         }
        tmp={x.ff+1, x.ss};
        if(tmp.ff>0 && tmp.ff<=n && tmp.ss>0 && tmp.ss<=m && a[tmp.ff][tmp.ss]!='#')
         {
            cnt++;
            if(tunnel[tmp.ff][tmp.ss].ff)
            {
                A[ y.ss ] [ ind[tunnel[tmp.ff][tmp.ss]] ]=-1;
            }
            else
                A[y.ss][ ind[tmp] ]=-1;
         }
        tmp={x.ff-1, x.ss};
        if(tmp.ff>0 && tmp.ff<=n && tmp.ss>0 && tmp.ss<=m && a[tmp.ff][tmp.ss]!='#')
         {
            cnt++;
            if(tunnel[tmp.ff][tmp.ss].ff)
            {
                A[ y.ss ] [ ind[tunnel[tmp.ff][tmp.ss]] ]=-1;
            }
            else
                A[y.ss][ ind[tmp] ]=-1;
         }
        if(!cnt)
        {
            A[y.ss][y.ss]=1;
            continue;
        }
        A[y.ss][y.ss]=cnt;
    }
    gauss();
    cout<<ans[ind[start]];
}
