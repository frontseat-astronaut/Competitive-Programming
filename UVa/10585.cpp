#include<bits/stdc++.h>
using namespace std;

int main()
{
	int c;
	cin>>c;

	while(c--)
	{
		int n;

		vector <float> X;
		vector <float> Y;

		for(int i=0; i<n; ++i)
		{
			float x,y;
			cin>>x>>y;

			X.push_back(x);
			Y.push_back(y);
		}

		sort(X.begin(),X.end());
		sort(Y.begin(),Y.end());

		bool ans=true;

		float sx=(X[0]+X[n-1])/2;
		float sy=(Y[0]+Y[n-1])/2;

		for(int i=1; i<ceil((float)n/2); ++i)
		{
			float zero = (X[i]+X[n-i-1])/2 -sx;
			if(zero<0.0000000001)
			{
				ans=false;
				break;
			}

			zero = (Y[i]+Y[n-i-1])/2 -sy;
			if(zero<0.0000000001)
			{
				ans=false;
				break;
			}
		}
		if(ans)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
}
