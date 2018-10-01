#include<iostream>
#include<vector>
using namespace std;
int a[5];
bool backtrack(int i, int val, vector<bool>map)
{
	if(i==5)
	{
		return (val==23);
	}

	for(int j=0; j<5; ++j)
	{
		if(!map[j]) continue;
		map[j]=0;
		if(backtrack(i+1, val*a[j], map))
			return 1;
		if(backtrack(i+1, val-a[j], map))
			return 1;
		if(backtrack(i+1, val+a[j], map))
			return 1;
		map[j]=1;
	}
	return 0;
}

int main()
{
	bool zero;
	bool ans;
	while(1)
	{
		zero=1;
		vector<bool> map(5);
		for (int i = 0; i < 5; ++i)
		{
			cin>>a[i];	
			if(a[i]) zero=0;
			map[i]=1;	
		}
		if(zero)
			break;
		ans=0;
		for(int i=0; i<5; ++i)
		{
			map[i]=0;
			if(backtrack(1,a[i], map))
			{
				ans=1;
				break;
			}
			map[i]=1;
		}
		if(ans)
			cout<<"Possible"<<endl;
		else
			cout<<"Impossible"<<endl;
	}
}