#include<iostream>
using namespace std;
int N;
int a[1000001];;
void in(int tail[], int k, int a)
{
    int l=0, r=k-1, m, i=l-1;
    while(l<=r)
    {
        m=(l+r)/2;
        if(a==tail[m])
        {
            return;
        }
        if(a<tail[m])
        {
            r=m-1;
            i=m;
        }
        else 
        {
            l=m+1;
        }
    }
    tail[i]=a;
}
int LIS()
{
    int tail[N];
    int k=0;
    tail[k++]=a[0];
    for(int i=1; i<N; ++i)
    {
//        for(int j=0; j<k; ++j)
//            cout<<tail[j]<<" ";
//        cout<<endl;
        if(a[i]>tail[k-1])
        {
            tail[k++]=a[i];
        }
        else if(a[i]<tail[0])
            tail[0]=a[i];
        else 
        {
            in(tail, k, a[i]);
        }
    }
    return k;
}
int main()
{
    cin>>N;
    for (int i = 0; i < N; ++i)
    {
        cin>>a[i];
    }
    cout<<LIS()<<endl;
}