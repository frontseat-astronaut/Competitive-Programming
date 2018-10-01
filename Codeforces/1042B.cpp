#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
int32_t main()
{
	int n;
	cin>>n;

	vector<int>ABC, A, B, C, AB, BC, AC;
	for(int i=0; i<n; ++i)
	{
		int c;
		string vit;
		cin>>c>>vit;
		bool V[256]={};
		for(auto v:vit)
		{
			V[v]=1;
		}
		if(V['A'] && V['B'] && V['C'])
		{
			ABC.push_back(c);
		}
		else if(V['A'] && V['B'])
		{
			AB.push_back(c);
		}
		else if (V['A']&& V['C'])
		{
			AC.push_back(c);
		}
		else if (V['B']&& V['C'])
		{
			BC.push_back(c);
		}
		else if(V['A'])
		{
			A.push_back(c);
		}
		else if(V['B'])
		{
			B.push_back(c);
		}
		else if(V['C'])
		{
			C.push_back(c);
		}
	}

	sort(ABC.begin(), ABC.end());
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());
	sort(AB.begin(), AB.end());
	sort(AC.begin(), AC.end());
	sort(BC.begin(), BC.end());
	
	int minm=500000001;
	if(ABC.size())
	{
		minm=ABC[0];
	}
	if (AB.size() && C.size())
	{
		minm=min(minm, AB[0]+C[0] );
	}
	if (AC.size() && B.size())
	{
		minm=min(minm, AC[0]+B[0] );
	}
	if (BC.size() && A.size())
	{
		minm=min(minm, BC[0]+A[0] );
	}
	if (A.size() && C.size() && B.size())
	{
		minm=min(minm, A[0]+C[0]+B[0] );
	}
	if(AB.size() && BC.size())
	{
		minm=min(minm, AB[0]+BC[0]);
	}
	if(AB.size() && AC.size())
	{
		minm=min(minm, AB[0]+AC[0]);
	}
	if(AC.size() && BC.size())
	{
		minm=min(minm, AC[0]+BC[0]);
	}

	if(minm==500000001)
		cout<<-1<<endl;
	else
		cout<<minm<<endl;
}