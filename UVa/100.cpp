#include<iostream> 
#include<unordered_map>
using namespace std;

unordered_map <int,int> M;

int coltz(int x)
{
	if(x==1)
		return 1;
	if(M[x]!=0)
	{
		return M[x];
	}
	if(x%2==0)
	{
		M[x]=1+coltz(x/2);
		return M[x];
	}
	else
	{
		M[x]=2+coltz((3*x+1)/2);
		return M[x];
	}	
}

int main()
{
	int I,J;
	while(cin>>I)
	{
		cin>>J;
		int L,R;
		if(J<I)
		{
			L=J;
			R=I;
		}
		else
		{
			L=I;
			R=J;
		}
		int max=coltz(L);
		for(int i=L+1; i<=R; ++i)
		{
			int temp=coltz(i);
			if(temp>max)
				max=temp;
//			cout<<i<<" "<<temp<<endl;
		}
		cout<<I<<" "<<J<<" "<<max<<endl;
	}
}