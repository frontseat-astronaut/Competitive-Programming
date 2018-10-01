#include<iostream>
#include<map>
using namespace std;

int main()
{
	int t;
	cin>>t;
//	cout<<t<<endl;

	map<int,int> m;

	for(int i=0; i<t; ++i)
	{
		int x;
		cin>>x;
		m[x]++;
	}
//	cout<<m[2]<<endl;
	bool flag=false;
	for(int f=1; f*f<=t; ++f)
	{
		if(t%f!=0) continue;
		cout<<f<<endl;
		int n[2]={f,t/f};
		int space[4]={0};

		map<int,int> M=m;
		for(int i=1; M[i]>0; ++i)
		{
			int j=0;
			while(M[i] && j<4 )
			{
				if(space[j]+2+space[(j+2)%4]>n[(j)%2])
				{
					++j;
					continue;
				}

				M[i]--;
				space[j]++;
				int added_length=space[(j+1)%4]+space[(j+3)%4];
				for(int k=i+1; added_length>0; ++k)
				{
					M[k]--;
					added_length--;
					if(added_length>0) 
					{
						added_length--;
						M[k]--;
					}
				}
				++j;
			}
			cout<<space[0]<<" "<<space[1]<<" "<<space[2]<<" "<<space[3]<<endl;
		}
		cout<<endl<<"left out: "<<endl;
		bool correct=true;
		for(int i=1; m[i]>0; ++i)
		{
			if(M[i]!=0)
			{
				correct=false;
				cout<<i<<" "<<M[i]<<endl;
				break;
			}
		}
		cout<<endl<<endl;
		if(!correct) continue;
		flag=true;
		cout<<space[1]+space[3]+1<<" "<<space[0]+space[2]+1<<endl;
		cout<<space[3]+1<<" "<<space[2]+1<<endl;
		break;
	}
	if(!flag)
	{
		cout<<-1<<endl;
	}
}
