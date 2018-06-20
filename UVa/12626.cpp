#include<iostream>
using namespace std;
int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		string S;
		cin>>S;

		int ch[256]={0};

		for(int i=0; S[i]!='\0'; ++i)
		{
			ch[S[i]]++;
		}

		int arr[6]={0};
		arr[0]=ch['M'];
		arr[1]=ch['A']/3;
		arr[2]=ch['R']/2;
		arr[3]=ch['G'];
		arr[4]=ch['I'];
		arr[5]=ch['T'];

		int min=arr[0];

		for(int i=0; i<6; ++i)
			if(min>arr[i])
				min=arr[i];
		cout<<min<<endl;
	}
}