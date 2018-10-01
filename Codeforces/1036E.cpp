#include<iostream>
#include<set>
#include<math.h>
#define int long long
using namespace std;
struct point
{
	int x,y;
};
struct line
{
	int Ax, Ay, Bx, By;
};
struct cmp
{
	bool operator() (point const &a, point const &b) const
	{
		if(a.x==b.x)
			return a.y<b.y;
		return a.x<b.x;
	}
};
bool lineLineIntersection(point A, point B, point C, point D, point &I)
{
    // Line AB represented as a1x + b1y = c1
    int a1 = B.y - A.y;
    int b1 = A.x - B.x;
    int c1 = a1*(A.x) + b1*(A.y);
 
    // Line CD represented as a2x + b2y = c2
    int a2 = D.y - C.y;
    int b2 = C.x - D.x;
    int c2 = a2*(C.x)+ b2*(C.y);
 
    int determinant = a1*b2 - a2*b1;
 
    if (determinant == 0)
    {
        // The lines are parallel. This is simplified
        // by returning a pair of FLT_MAX
        return 0;
    }
    else
    {
    	if((b2*c1 - b1*c2)%determinant || (a1*c2 - a2*c1)%determinant)
    	{
    		return 0;
    	}
        int x = (b2*c1 - b1*c2)/determinant;
        int y = (a1*c2 - a2*c1)/determinant;
        if(x<=max(A.x, B.x)&&x>=min(A.x, B.x)&&y<=max(A.y, B.y)&&y>=min(A.y, B.y))
        {
        	I={x,y};
        	return 1;
        }
        return 0;
    }
}
int32_t main()
{
	int n;
	cin>>n;
	line L[n];
	set<point, cmp>P;
	for(int i=0; i<n; ++i)
	{
		cin>>L[i].Ax>>L[i].Ay>>L[i].Bx>>L[i].By;
		P.insert({L[i].Ax,L[i].Ay});
		P.insert({L[i].Bx,L[i].By});
	}
	for(int i=0; i<n; ++i)
	{
		for(int j=i+1; j<n; ++j)
		{
			point I;
			if(lineLineIntersection({L[i].Ax,L[i].Ay},{L[i].Bx,L[i].By},{L[j].Ax,L[j].Ay},{L[j].Bx,L[j].By},I))
				P.insert(I);
		}
	}
	int ans=P.size();
	for(int i=0; i<n; ++i)
	{
		int Ax=L[i].Ax, Bx=L[i].Bx, Ay=L[i].Ay, By=L[i].By; 
		int p=By-Ay;
		int q=Bx-Ax;
		int cnt=0;
		for(auto poi:P)
		{
			if((poi.y-Ay)*q==p*(poi.x-Ax))
			{
				cnt++;
			}
		}
		if(q==0)
		{
			ans-=cnt;
			ans+=fabs(p)+1;
			continue;
		}
		if(p==0)
		{		
			ans-=cnt;
			ans+=fabs(q)+1;
			continue;
		}
		ans-=cnt;
		int l=0, x=Ax;
		while(x<=Bx)
		{
			if(q*l%p==0)
			{
				ans++;
			}
			x=q*l/p+Ax;
			++l;
		}
	}
	cout<<ans<<endl;
//	for(auto p:P)
//		cout<<p.x<<" "<<p.y<<endl;
}