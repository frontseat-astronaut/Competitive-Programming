#include<bits/stdc++.h>
using namespace std;

struct markers
{
	float x,y;
	int sno;
};

bool cmpx(markers a, markers b)
{
	return a.x<b.x;
}
bool cmpy(markers a, markers b)
{
	return a.y<b.y;
}

int main()
{
	int n,caseno=0;
	while(true)
	{
		caseno++;
		cin>>n;

		if(!n)
			break;

		vector <markers> X;
		vector <markers> Y;
		map <int,bool> present;

		for(int i=0; i<n; ++i)
		{
			float x,y,r;
			cin>>x>>y>>r;

			if(r==0)
			{
				n--;
				i--;
				continue;
			}

			X.push_back({x-r,y,i+1});
			X.push_back({x+r,y,-i-1});

			Y.push_back({x,y-r,i+1});
			Y.push_back({x,y+r,-i-1});
				
		}
		sort(X.begin(), X.end(), cmpx);
		sort(Y.begin(), Y.end(), cmpy);	
/*
		for(auto temp:Y)
		    cout<<temp.sno<<"-"<<temp.y<<" ";
		cout<<endl;
		for(auto temp:X)
		    cout<<temp.sno<<"-"<<temp.x<<" ";
		cout<<endl;
*/
		float area=0;
		for(int i=0; i<2*n-1; ++i)
		{
			float x=X[i].x, y=X[i].y;
			int sno=X[i].sno;

			if(sno>0)
				present[sno]=1;
			else
				present[-sno]=0;

			int layers=0;
			float width=0, start;

			for(int j=0; j<2*n; ++j)
			{
				if(present[fabs(Y[j].sno)]==0) continue;

				cout<<Y[j].sno<<"-"<<Y[j].y<<" ";

				if(layers==0)
				{
					start=Y[j].y;
				}

				if(sno>0)
				{
					++layers;
				}
				else
					--layers;

				if(layers==0)
				{
				    cout<<"yoho ";
					width+=Y[j].y-start;
				}
			}
			cout<<endl;
			area+=width*(X[i+1].x-X[i].x);
		}
		printf("%d %.2f\n",caseno,area);
	}
}


