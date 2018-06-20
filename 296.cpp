#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
//go brute force!!
struct guess
{
	char num[5];
	int correct, misplaced;
};

int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		int G;
		cin>>G;
		guess g[G];

		for(int i=0; i<G; ++i )
		{
			cin>>g[i].num;
			char ch;
			cin>>g[i].correct>>ch>>g[i].misplaced;
		}
//		cout<<g[1].num<<" "<<g[1].correct<<" "<<g[1].misplaced<<endl;

		int count=0;
		char num[5];
		for(char i='0'; i<='9'; ++i)
		{
			for(char j='0'; j<='9'; ++j)
			{
				for(char k='0'; k<='9'; ++k)
				{
					for(char l='0'; l<='9'; ++l)
					{
						char n[5]={i,j,k,l,'\0'};
						bool match=true;
						for(int m=0; m<G; ++m)
						{
							int correct=0;
							int misplaced=0;
							int num_map[10]={};

							for(int p=0; p<4; ++p)
							{
								if(n[p]==g[m].num[p])
									++correct;
								else num_map[n[p]-'0']++;
							}
							if(correct!=g[m].correct)
							{
								match=false;
								break;
							}
							for(int p=0; p<4; ++p)
							{
								if(num_map[g[m].num[p]-'0'] && n[p]!=g[m].num[p])
								{
									++misplaced;
									num_map[g[m].num[p]-'0']--;
								}
							}
							if(misplaced!=g[m].misplaced)
							{
								match=false;
								break;
							}
						}

						if(match)
						{
							count++;
							strcpy(num,n);
							if(count>1)
							{
								break;
							}
						}
					}
					if(count>1)
					{
						break;
					}
				}
				if(count>1)
				{
					break;
				}
			}
			if(count>1)
			{
				break;
			}
		}
		
		if(count==0)
			cout<<"impossible"<<endl;
		else if(count==1)
			cout<<num<<endl;
		else
			cout<<"indeterminate"<<endl;
		
	}
}