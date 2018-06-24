#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;

	queue <int> lm[26];
	char str[n];
	cin>>str;

	for(int i=0; i<n; ++i)
	{
		lm[str[i]-'a'].push(i);
	}

	for(int i=0; i<k; ++i)
	{
		for(char ch='a'; ch<='z'; ++ch)
		{
			if(lm[ch-'a'].size())
			{
				lm[ch-'a'].pop();
				break;
			}
		}
	}

	for(int i=0; i<n; ++i)
	{
		if(lm[str[i]-'a'].size())
		{
			if(lm[str[i]-'a'].front()==i)
			{
				cout<<str[i];
				lm[str[i]-'a'].pop();
			}
		}
	}
	cout<<endl;
}