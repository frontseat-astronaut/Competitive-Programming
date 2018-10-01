#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

int main()
{
	int C, S;
	int caseno=1;
	while(cin>>C>>S)
	{
		int m[S];
		 double avg=0;
		for(int i=0; i<S; ++i)
		{
			cin>>m[i];
			avg+=m[i];
		}
		avg/=C;

		sort(m, m+S);

		int i=S-1, c=0;
		bool dir=0;
		vector <int> cm[C];
		while(i>=0)
		{
			cm[c].push_back(m[i]);
			i--;
			if(c==0 && dir==1)
				dir=!dir;
			else if (c==C-1 && dir==0)
				dir=!dir;
			else
			{
				if(dir) c--;
				else c++;
			}
		}

		 double imb=0;
		printf("Set #%d\n", caseno++);
		for(int i=0; i<C; ++i)
		{
			 double sum=0;
			cout<<" "<<i<<":";
			for(auto m:cm[i])
			{
				sum+=m;
				cout<<" ";
				cout<<m;
			}
			cout<<endl;
			imb+=fabs(sum-avg);
		}
		printf("IMBALANCE = %.5f\n", imb);
		cout<<endl;
	}
}