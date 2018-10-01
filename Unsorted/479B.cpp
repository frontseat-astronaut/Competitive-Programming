#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct towers
{
	int c, id;
};

bool cmp(towers a, towers b)
{
	return a.c<b.c;
}

int main()
{
	int n,k;
	cin>>n>>k;
	towers a[n];
	for(int i=0; i<n; ++i)
	{
		a[i].id=i+1;
		cin>>a[i].c;
	}

	int m=0, s;
	sort(a, a+n, cmp);
	vector<pair<int,int>>moves;
	while(m<k)
	{
		if(a[n-1].c==a[0].c)
			break;
		do
		{
			a[n-1].c--;
			a[0].c++;
			moves.push_back({a[n-1].id, a[0].id});
			m++;
		}
		while(a[0].c<=a[1].c && a[n-2].c<=a[n-1].c && m<k && a[0].c<a[n-1].c);
		sort(a, a+n, cmp);
	}
	cout<<a[n-1].c-a[0].c<<" "<<m<<endl;
	for(auto m: moves)
		cout<<m.first<<" "<<m.second<<endl;
}