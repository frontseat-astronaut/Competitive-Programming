#include<bits/stdc++.h>
using namespace std;

struct marker
{
	float value;
	float x;
	bool type;
};

bool cmp(marker a, marker b)
{
	return a.x<b.x;
}

int main() 
{
	int f,g;
	while(cin>>g)
	{
		vector <marker> X;

		float x=0;
	    for(int i=0; i<g; ++i)
	    {
	    	float value, step;

	    	cin>>value;
	    	cin>>step;

	    	X.push_back({value,x,0});
	    	x+=step;

	    }

	    cin>>f;

	    x=0;
	    for(int i=0; i<f; ++i)
	    {
	    	float value, step;

	    	cin>>value;
	    	cin>>step;

	    	X.push_back({value,x,1});
	    	x+=step;

	    }

	    sort(X.begin(),X.end(),cmp);

	    float minh;
	    bool flag=0;
	    float F, G;
	    float h_value;
	    for(int i=0; i<(f+g); ++i)
	    {
	    	if(X[i].type==0)
	    		G=X[i].value;
	    	else
	    		F=X[i].value;

	    	if(X[i].x==X[i+1].x)
	    	{
	    		if(X[i+1].type==0)
	    			G=X[i+1].value;
	    		else
	    			F=X[i+1].value;
	    		i++;
	    	}
	    	h_value=max(F,G);
//	    	cout<<h_value<<" ";
	    	if(flag==0)
	    	    minh=h_value;
	    	minh=min(h_value,minh);
	    	flag=1;
	    }
//	    cout<<endl;
	    printf("%.3f\n",minh);
	}
	return 0;
}