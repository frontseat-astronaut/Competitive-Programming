#include<bits/stdc++.h>
using namespace std;
struct str
{
	string a;
	int len;
	bool operator<(str const &other) const
	{
		if(len!=other.len)
			return len<other.len;
		return lexicographical_compare(a.begin(), a.end(), other.a.begin(), other.a.end());
	}
};
int main()
{
	set<str>m;
	m.insert({"0110",4});
	m.insert({"1001",1});
	auto it=m.begin();
	++it;
	auto it1=it;
	--it;
	cout<<(it-m.begin()<it1-m.begin())<<endl;

}