#include<iostream>
#include<set>
using namespace std;

int main()
{
	int n;
	cin>>n;

	switch(n)
	{
		case 1: cout<<4<<endl;
				return 0;
		case 2: cout<<10<<endl;
				return 0;
		case 3: cout<<20<<endl;
				return 0;
		case 4: cout<<35<<endl;
				return 0;
		case 5: cout<<56<<endl;
				return 0;
		case 6: cout<<83<<endl;
				return 0;
		case 7: cout<<116<<endl;
				return 0;
		case 8: cout<<155<<endl;
				return 0;
		case 9: cout<<198<<endl;
				return 0;
		case 10: cout<<244<<endl;
				return 0;
		case 11: cout<<292<<endl;
				return 0;
		default: cout<<292 + (long long)(n-11)*49<<endl;
				break;
	}

}