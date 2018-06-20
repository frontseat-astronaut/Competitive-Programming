#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
	int T, caseno=1;
	cin>>T;
	while(T--)
	{
		int N,M,K;
		cin>>N>>M>>K;

		if(K==1)
		{
			cout<<"Case "<<caseno++<<": ";
			cout<<1<<endl;
			continue;
		}

		map <int,int> X;
		X[1]=1; X[2]=2; X[3]=3;
		int var1=1, var2=2, var3=3;

		for(int i=4; i<=N; ++i)
		{
			int temp=(var1+var2+var3)%M+1;
			var1=var2;
			var2=var3;
			var3=temp;

			if(temp<=K)
				X[i]=temp;
		}	

/*
		for(auto x:X)
			cout<<x.second<<" ";
		cout<<endl;
		for(auto x:X)
			cout<<x.first<<"|";
		cout<<endl;
*/
		unordered_map <int,int> arr;
		arr[0]++;
		int k=1;
		int length=1;
		int minm=N+2;

		for( auto i=X.begin(), j=X.begin(); j!=X.end(); )
		{
//			cout<<(*i).second<<" "<<(*j).second<<" "<<length;
			if(k==K)
			{
//				cout<<" *";
				minm=min(minm, length);
			}
//			cout<<endl;

			if( arr[(*i).second-1]>1 )
			{
				auto temp=i;
				temp++; 

				length-=(*temp).first-(*i).first;
				arr[(*i).second-1]--;
				++i;

				if(k==K)
				{
					minm=min(length,minm);
				}
				continue;
			}

			auto temp=j;
			temp++;
			if(temp==X.end())
				break;

			length+=(*temp).first-(*j).first;
			if(arr[(*temp).second-1]==0) k++;
			arr[(*temp).second-1]++;
			++j;
		}
		if(k==K)
			minm=min(length,minm);

		cout<<"Case "<<caseno++<<": ";
		if(minm==N+2)
			cout<<"sequence nai"<<endl;
		else
			cout<<minm<<endl;

	}
}