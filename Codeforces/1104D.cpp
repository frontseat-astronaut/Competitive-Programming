#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
    while(1)
    {
        string s;
        cin>>s;
        if(s!="start") exit(0);
        int k, x, y, l, r, mid;
        char res;

        cout<<"? "<<0<<' '<<1<<"\n";
        fflush(stdout);
        cin>>res;
        if(res=='x')
        {
            cout<<"! 1\n";
            fflush(stdout);
            continue;
        }

        x=1, y=2;
        while(y<=2e9)
        {
            cout<<"? "<<x<<" "<<y<<"\n";
            fflush(stdout);
            cin>>res;
            if(res=='x')
            {
                l=x/2+1;
                r=x;
                break;
            }
            x<<=1;
            y<<=1;
        }
        while(l<r)
        {
            mid=(l+r)>>1;
            cout<<"? "<<mid<<" "<<mid*2<<"\n";
            fflush(stdout);
            cin>>res;
            if(res=='x')
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        mid=(l+r)>>1;
        cout<<"? "<<0<<' '<<mid*2<<endl;
        fflush(stdout);
        cin>>res;
        if(res=='x')
        {
            cout<<"! "<<mid*2<<endl;
            fflush(stdout);
        }
        else
        {
            cout<<"! "<<mid*2-1<<endl;
            fflush(stdout);
        }
    }
}