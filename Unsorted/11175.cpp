#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct vertex
{
	vector<int>in, out;
	int id;
	bool loop;
};
struct e
{
	bool made;
	int tail, tip;
};

vector<int> I(vector<int> v1, vector<int> v2)
{
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
 
    vector<int> v_intersection;
 
    set_intersection(v1.begin(), v1.end(),
                          v2.begin(), v2.end(),
                          back_inserter(v_intersection));

	sort(v_intersection.begin(), v_intersection.end());
    return v_intersection;
}

bool cmp(vertex a, vertex b)
{
	return a.out.size()+a.in.size()>b.out.size()+b.in.size();
}

int main()
{
	int N;
	cin>>N;
	int caseno=1;
	while(N--)
	{
		int m,k;
		cin>>m>>k;

		vector<vertex>E(m);
		for(int i=0; i<m; ++i)
		{
			E[i].id=i;
			E[i].loop=false;
		}
		for(int i=0; i<k; ++i)
		{
			int x,y;
			cin>>x>>y;
//			if(caseno==15)
//				cout<<x<<" "<<y<<endl;	

			E[x].out.push_back(y);
			E[y].in.push_back(x);
			if(x==y) E[x].loop=true;
		}
		sort(E.begin(), E.end(), cmp);

		vector<vertex>D;
		int n=0;
		bool ans=true;
		vector<e>edge(m);
		for(auto d: edge) d.made=false;

		for(int i=0; i<m; ++i)
		{
//tail
			bool found=false;
			for(auto prev:E[i].in)
			{
				for(int k=0; k<m; ++k)
				{
					if(E[k].id==prev)
						for(auto next: E[k].out)
						{
							if(edge[next].made)
							{
								D[edge[next].tail].out.push_back(E[i].id);
								edge[E[i].id].tail=edge[next].tail;
								if(E[i].loop)
								{
									D[edge[next].tail].in.push_back(E[i].id);
									edge[ E[i].id ].tip=edge[ E[i].id ].tail;
								}
								found =true;
								break;
							}
							if(found) break;
						}
				}
			}
			if(!found)
				for(int j=0; j<n; ++j)
				{				
					if(I(D[j].in,E[i].in).size())
					{
						D[j].out.push_back(E[i].id);
						edge[ E[i].id ].tail=j;

						if(E[i].loop)
						{
							D[j].in.push_back(E[i].id);
							edge[ E[i].id ].tip=j;
						}
						found=true;
						break;
					}
				}
			if(!found)
			{
				vertex v;
				v.out.push_back(E[i].id);
				edge[ E[i].id ].tail=n;
				if(E[i].loop)
				{
					v.in.push_back(E[i].id);
					edge[ E[i].id ].tip=n;					
				}
				D.push_back(v);
				++n;
			}
			if(E[i].loop)
			{
				continue;
				edge[ E[i].id ].made=true;	
			}
//tip
			found=false;
			for(auto next:E[i].out)
			{
				for(int k=0; k<m; ++k)
				{
					if(E[k].id==next)
					for(auto prev: E[k].in)
					{
						if(edge[prev].made)
						{
							D[edge[prev].tip].in.push_back(E[i].id);
							edge[E[i].id].tip=edge[prev].tip;
							found =true;
							break;
						}
						if(found) break;
					}
				}
			}
			if(found)
			{
				edge[ E[i].id ].made=true;
				continue;
			}
			for(int j=0; j<n; ++j)
			{
				if(I(D[j].out,E[i].out).size())
				{
					D[j].in.push_back(E[i].id);
					edge[ E[i].id ].tip=j;
					found=true;
				}
				if(found) break;
			}
			if(!found)
			{
				vertex v;
				v.in.push_back(E[i].id);
				edge[ E[i].id ].tip=n;
				D.push_back(v);
				++n;
			}
			edge[ E[i].id ].made=true;			
		}
		for(int i=0; i<m; ++i)
		{
			bool found=false;
			sort(E[i].in.begin(), E[i].in.end());
			for(int j=0; j<n; ++j)
			{
				sort(D[j].in.begin(), D[j].in.end());
				if(D[j].in==E[i].in)
				{
					found=true;
					break;
				}
			}
			if(!found)
			{
				ans=false;
				break;
			}

			found=false;
			sort(E[i].out.begin(), E[i].out.end());
			for(int j=0; j<n; ++j)
			{
				sort(D[j].out.begin(), D[j].out.end());
				if(D[j].out==E[i].out)
				{
					found=true;
					break;
				}
			}
			if(!found)
			{
				ans=false;
				break;
			}
		}
/*
		if(caseno!=15)
		{
			++caseno;
			continue;
		}
		cout<<m<<" "<<k<<endl;
		for(int i=0; i<n; ++i)
		{
			cout<<i<<": "<<endl;
			for(auto in:D[i].in)
				cout<<in<<" ";
			cout<<endl;
			for(auto out:D[i].out)
				cout<<out<<" ";
			cout<<endl<<endl;
		}
*/
		cout<<"Case "<<"#"<<caseno++<<": ";
		if(ans) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}