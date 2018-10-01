#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;

struct turtle
{
	long long w, s;
	bool done;
};

bool cmp(turtle a, turtle b)
{
	return a.w<b.w;
}

int f(vector<turtle>T, long long weight, long long limit)
{	
	int maxm=-1, maxw=-1;
	vector<int> nexti;
	for(int i=0; i<N; ++i)
	{
		if(T[i].w>limit-weight || T[i].done) continue;
		long long c=min(limit, weight+T[i].s)-weight-T[i].w;
		long long sum=0;
		int count=0;
		for(int j=0; j<N; ++j)
			if(!T[j].done && i!=j) 
			{
				sum+=T[j].w;
				if(sum>c)
					break;
				count++;
			}

		if(count>maxm)
		{
			maxm=count;
			maxw=T[i].w;
			nexti.clear();
			nexti.push_back(i);
		}
		else if (count==maxm)
		{
			if(maxw<T[i].w)
			{
				maxw=T[i].w;
				nexti.clear();
				nexti.push_back(i);
			}
			else if (maxw==T[i].w)
				nexti.push_back(i);
		}

	}
	if(!nexti.size()) return 0;

	maxm=0;
	for(auto ni: nexti)
	{
		T[ni].done=1;
		long long temp=min(limit, weight+T[ni].s);

		int ans=f(T, weight+T[ni].w, temp);
		if(ans>maxm)
			maxm=ans;

		T[ni].done=0;
	}
	return maxm+1;
}

int main()
{
	vector<turtle>T;
	long long w,s;
	while(cin>>w>>s)
	{
		if(w>s) continue;
		T.push_back({w,s,0});
		N++;
	}
	sort(T.begin(), T.end(), cmp);	
	long long limit=9223372036854775807, weight=0;

	cout<<f(T,weight,limit)<<endl;
}