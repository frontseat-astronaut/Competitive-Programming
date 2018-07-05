#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

bool check(char S[101], int L, char &mid)
{
	int count[256]={0};
	for(int i=0; i<L; ++i)
	{
		count[S[i]]++;
	}
	if(L%2==0)
	{
		for(char j='a'; j<='z'; ++j)
		{
			if(count[j]%2==1)
				return false;
		}
	}
	else
	{
		bool mid_found=0;
		for(char j='a'; j<='z'; ++j)
		{
			if(count[j]%2==1)
			{
				if(mid_found==1)
					return false;
				mid_found=1;
				mid=j;
			}
		}
	}
	return true;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		char S[101];
		scanf("%s",S);

		int L=strlen(S);
		char mid;
		if(check(S,L,mid)==false) 
		{
			cout<<"Impossible"<<endl;
			continue;
		}

		int swaps=0, k, midindex;
		for(int i=0, j=L-1; i<j; ++i, --j)
		{
//			cout<<S<<endl;
			if(S[i]==S[j])
			{
				continue;
			}

			for(k=j-1; k>i; --k)
				if(S[k]==S[i])
					break;

			if(k==i)
			{
				midindex=k;
				j++;
				continue;
			}

			for( ; k<j; ++k)
			{
				swap(S[k],S[k+1]);
				++swaps;
			}
			S[k]=S[i];
		}
		if(L%2==1)
		{
			if(S[L/2]!=mid) 
				for(k=midindex+1; k<=L/2; ++k)
				{
					swap(S[k],S[k-1]);
					++swaps;
				}
		}
		
//		cout<<S<<endl;
		cout<<swaps<<endl;
	}
}