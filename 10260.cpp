#include<bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	while(cin>>S)
	{
		int ch[256]={0};
		ch['B']=ch['F']=ch['P']=ch['V']=1;
		ch['C']=ch['G']=ch['J']=ch['K']=ch['Q']=ch['S']=ch['X']=ch['Z']=2;
		ch['D']=ch['T']=3;
		ch['L']=4;
		ch['M']=ch['N']=5;
		ch['R']=6;

		char ans[21];
		int k=0;
		int prev=0;

		for(int i=0; S[i]!='\0';  prev=ch[S[i]], ++i)
		{
			if(ch[S[i]]==0)
				continue;
			if(prev!=ch[S[i]])
				ans[k++]=ch[S[i]]+'0';

		}	
		ans[k]='\0';
		cout<<ans<<endl;	
	}	
}