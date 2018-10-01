#include<bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	while(cin>>S)
	{
		if(S=="0")
			break;
		stack <char>atoms, op, N;
		for(auto ch: S)
		{
			if(islower(ch))
			{
				atoms.push(ch);
			}
			else if(ch=='N')
				N.push(ch);
			else
				op.push(ch);
		}
		if(atoms.empty())
		{
			cout<<"no WFF possible"<<endl;
			continue;
		}
		stack <char>ans;
		ans.push(atoms.top());
		atoms.pop();
		while(N.size())
		{
			ans.push('N');
			N.pop();
		}
		while(true)
		{
			if(op.empty() || atoms.empty())
				break;
			ans.push(atoms.top());
			atoms.pop();
			ans.push(op.top());
			op.pop();
		}
		while(ans.size())
		{
			cout<<ans.top();
			ans.pop();
		}
		cout<<endl;
	}
}