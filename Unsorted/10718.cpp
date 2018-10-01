#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	unsigned int L,U;
	unsigned long long N, M;
	while(cin>>N>>L>>U)
	{
		M=L;
		unsigned int b=pow(2,(int)log2(U));
//		cout<<b<<endl;
		while(b>0)
		{
			if((b&N)==0)
			{
				if((M|b)<=U)
				{
					M=M|b;
				}
				else if (U|b)
				{
					unsigned int temp=M|b;
					unsigned int k=b/2;
					while(k && temp>U)
					{
						if((N&k) && (temp&k) && ((temp^k)>=L))
						{
							temp=temp^k;
						}
						k/=2;
					}
					if(temp>U)
					{
						k=1;
						while(k<b && temp>U)
						{
							if((temp&k) && ((temp^k)>=L))
							{
								temp=temp^k;
							}
							k*=2;
						}
					}
					if(temp<=U)
						M=temp;
				}
			}
			else if ((b&M))
			{
				if((M^b)>=L)
				{
					M=M^b;
				}
			}
			b/=2;
		}

		unsigned int k=pow(2,(int)log2(U));
		while(k)
		{
			if((N&k) && (M&k) && ((M^k)>=L))
			{
				M=M^k;
			}
			k/=2;
		}
		cout<<M<<endl;
	} 
}