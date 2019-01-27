#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int m=1e9+7;
int fact[200], ifact[200];
int powr(int a, int r)
{
    if(!r) return 1;
    int tmp=powr(a, r>>1);
    tmp=(tmp*tmp)%m;
    if(r&1) tmp=(tmp*a)%m;
    return tmp;
}
int inv(int a)
{
    return powr(a, m-2);
}
int C(int n, int r)
{
    if(n<r) return 0;
    int tmp=(fact[n]*ifact[r])%m;
    tmp=(tmp*ifact[n-r])%m;
    return tmp;
}
int32_t main()
{
    fact[0]=1; ifact[0]=1;
    for(int i=1; i<=200; ++i)
    {
        fact[i]=(fact[i-1]*i)%m;
        ifact[i]=inv(fact[i]);
    }
    int a[101];
    a[0]=1;
    for(int i=1; i<=100; ++i) a[i]=4*i;

    int f[401][101][101]={};
    for(int k=1; k<101; ++k)
    {
        f[1][k][1]=1;
        f[1][k][0]=k;
    }
    for(int n=2; n<401; ++n)
    {
        for(int k=1; k<=min(n, (int)100); ++k)
        {
            for(int r=0; r<=k; ++r)
            {
                f[n][k][r]=( ( (k-r)*f[n-1][k][r] )%m + ( r*f[n-1][k][r-1] )%m )%m;
            }
        }
    }

    int dp[101][101]={};
    dp[0][1]=1;
    for(int n=1; n<101; ++n)
    {
        for(int k=1; k<=100; ++k)
        {
            for(int j=1; j<=min(a[n], k); ++j)
            {
                dp[n][k]=(dp[n][k] + ( (dp[n-1][k-j] * C(k,j))%m * f[a[n]][j][j] )%m )%m;
            }
        }
    }
    int t, k;
    cin>>t>>k;
    cout<<dp[t][k]<<endl;
}