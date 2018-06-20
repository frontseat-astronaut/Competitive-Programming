#include<bits/stdc++.h>
using namespace std;

struct point
{
	float x, y, r;
	int sno;
};

bool cmpx (point a, point b)
{
	return a.x<b.x;
}

struct cmpy
{
	bool operator()(const point& a, const point& b) const
	{
		return a.y<b.y;
	}
};

int main()
{
	int n, caseno=1;
	while(true)
	{
		cin>>n;

		if(!n)
			break;

		vector <point> X;
		map <point,int,cmpy> Y;

		for(int i=0; i<n; ++i)
		{
			float x,y,r;
			cin>>x>>y>>r;

			X.push_back({x-r,y,r,i+1});
			X.push_back({x+r,y,-r,i+1});
		}

		sort(X.begin(), X.end(), cmpx);

		float area=0;	

		for(int i=0; i<2*n-1; ++i)
		{
		    float x=X[i].x, y=X[i].y, r=X[i].r, sno=X[i].sno;
			if(r>0)
			{
				Y[{x,y-r,r,sno}]++;
				Y[{x,y+r,-r,sno}]++;
			}
			else if(r<0)
			{
			    Y[{x,y-r,r,sno}]--;
				Y[{x,y+r,-r,sno}]--;
				
				if(Y[{x,y-r,r,sno}]==0)
				{
				    auto it=Y.find({x,y+r,-r,sno});
			        Y.erase(it);
				}
			    
			    if(Y[{x,y+r,-r}]==0)
			    {
				    auto it=Y.find({x,y-r,r,sno});
				    Y.erase(it);
			    }
			}
			else
				continue;
				
            if(Y.empty())
                continue;
                
			int layers=0;
			float width=0, start;
			point curr;
			for (auto it=Y.begin(); it!=Y.end(); it++)
			{
			    curr=(*it).first;
//                  cout<<curr.y<<" ";

			    if(layers==0)
			    	start=curr.y;
			    
			    if(curr.r<0)
			        layers--;
			    else 
			        layers++;

				if(layers==0)
				{
					width+=curr.y-start; 
				}

			}
            cout<<endl;
			area+=width*(X[i+1].x-X[i].x);
		}

		printf("%d %.2f\n",caseno,area);
		caseno++;
	}
}