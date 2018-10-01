#include<bits/stdc++.h>
using namespace std;

struct v
{
	int id;
	vector<int>adj;
};

bool cmp(v a, v b)
{
	return a.adj.size()<b.adj.size();
}

vector<int> I(vector<int> v1, vector<int> v2)
{
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
 
    vector<int> v_intersection;
 
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v_intersection));

	sort(v_intersection.begin(), v_intersection.end());
    return v_intersection;
}

vector<int> U(vector<int> v1, vector<int> v2)
{
	vector<int> dest1;
	set_union(v1.begin(), v1.end(),v2.begin(), v2.end(), back_inserter(dest1));
	sort(dest1.begin(), dest1.end());
    return dest1;
}

bool f(vector<vector<int>>P, int n, vector<int>edges, vector<v>V, int m, int i)
{
	if(i==m) 
		return true;

	vector<int>req=I(edges,V[i].adj);
	sort(req.begin(), req.end());

	if(req.empty())
	{
		vector<int>new_vertex{V[i].id};
		P.push_back(new_vertex);
		P.push_back(new_vertex);
		n+=2;
		edges.push_back(V[i].id);

		return f(P,n,edges,V,m,i+1);
	}
	for(int j=0; j<n; ++j)
	{
		sort(P[j].begin(), P[j].end());
		if(P[j]==req)
		{
			P[j].push_back(V[i].id);

			vector<int>new_vertex{V[i].id};
			P.push_back(new_vertex);

			++n;
			edges.push_back(V[i].id);

			if(f(P,n,edges,V,m,i+1))
				return true;
			P[j].pop_back();
			P.pop_back();
			n--;
			edges.pop_back();
		}
		for(int k=j+1; k<n; ++k)
		{
			if(P[j].size()+P[k].size()!=req.size()) continue;
			if(I(P[j],P[k]).empty() && U(P[j],P[k])==req)
			{
				P[j].push_back(V[i].id);
				P[k].push_back(V[i].id);
				edges.push_back(V[i].id);
				if(f(P,n,edges,V,m,i+1))
					return true;
				P[j].pop_back();
				P[k].pop_back();
				edges.pop_back();
			} 
		}
	}
	return false;
}


int main()
{
	int N;
	cin>>N;
	int caseno=1;

	while(N--)
	{
		int m,p;
		cin>>m>>p;

		vector<v>V(m);
		for(int i=0; i<m; ++i)
			V[i].id=i;
		for(int i=0; i<p; ++i)
		{
			int x,y;
			cin>>x>>y;

			V[x].adj.push_back(y);
		}
		sort(V.begin(), V.end(),cmp);

		vector<vector<int>>P;
		int n=0;
		vector<int>edges;
		bool ans=f(P,0,edges,V,m,0);
		
//		if(caseno!=15) continue;
//		cout<<m<<" "<<p<<endl;
		cout<<"Case "<<"#"<<caseno++<<": ";
		if(ans) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}