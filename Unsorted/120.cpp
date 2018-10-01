#include<iostream>
#include<algorithm>
using namespace std;

int s[31], s_[31];
int n=0;

void flip(int k)
{
	for(int i=0; i<k; ++i, --k)
		swap(s[i],s[k]);
}

int main()
{
	while(cin>>s[0])
	{
		s_[n]=s[n];
		++n;
		char ch;
		while(1)
		{
			ch=getchar();
			if(ch=='\n')
				break;
			cin>>s[n++];
			s_[n-1]=s[n-1];
		}
		sort(s_,s_+n);

		for(int i=0; i<n; ++i)
		{
			if(i<n-1) cout<<s[i]<<" ";
			else cout<<s[i]<<endl;
		}

		for(int k=n-1; k>=0; --k)
		{
			if(s[k]==s_[k]) continue;
			if(s[0]==s_[k])
			{
				flip(k);
				cout<<n-k<<" ";
				continue;
			}
			int i;
			for( i=k-1; i>=0; --i)
			{
				if(s[i]==s_[k])
					break;
			}
			flip(i);
			cout<<n-i<<" ";
			flip(k);
			cout<<n-k<<" ";
		}
		cout<<0<<endl;

		n=0;
	}
}