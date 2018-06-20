#include<iostream>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;

	int key[10]={}, seq[n];

	for(int i=0; i<n; ++i)
		cin>>seq[i];
	for(int i=0; i<m; ++i)
	{
		int temp;
		cin>>temp;
		key[temp]++;
	}

	int k=0;
	int subseq[n];
	for(int i=0; i<n; ++i)
	{
		if(key[seq[i]])
			subseq[k++]=seq[i];
	}
	for(int i=0; i<k; ++i)
		cout<<subseq[i]<<" ";
	cout<<endl;

}