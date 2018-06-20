#include<bits/stdc++.h>
using namespace std;

int main()
{
	char code[100];
	while(scanf("%s",code)!=EOF)
	{
		int N;
		cin>>N;

//		cout<<code<<endl;

		stack <char> S;
		int sequence[N];

		int L=strlen(code);
		for(int i=0; i<L; ++i)
		{
			if(code[i]==']')
			{
				if(S.top()>='0' && S.top()<='9')
				{
					int num=0, k=0;
					while(S.top()>='0' && S.top()<='9')
					{
						num+=pow(10,k++)*(S.top()-'0');
						S.pop();
					}
					if(S.top()=='-')
					{
						num=-num;
						S.pop();
					}
					S.pop();
					for(int j=0; j<N; ++j)
						sequence[j]=num;
					continue;
				}
				if(S.top()=='+')
				{
					S.pop();
					int num=0, k=0;
					while(S.top()>='0' && S.top()<='9')
					{
						num+=pow(10,k++)*(S.top()-'0');
						S.pop();
					}
					S.pop();

					int temp[N];
					temp[0]=num;
					for(int j=1; j<N; ++j)
					{
						temp[j]=sequence[j-1]+temp[j-1];
					}
					for(int j=0; j<N; ++j)
					{
						sequence[j]=temp[j];
					}
					continue;
				}
				else
				{
					S.pop();
					int num=0, k=0;
					while(S.top()>='0' && S.top()<='9')
					{
						num+=pow(10,k++)*(S.top()-'0');
						S.pop();
					}
					S.pop();

					sequence[0]=num*sequence[0];
					for(int j=1; j<N; ++j)
					{
						sequence[j]=sequence[j]*sequence[j-1];
					}
					continue;	
				}
			}
			else
				S.push(code[i]);
		}
		for(int i=0; i<N; ++i)
		{
			cout<<sequence[i];
			if(i<N-1) cout<<" ";
		}
		cout<<endl;

	}
}