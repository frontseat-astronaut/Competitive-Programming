#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int b[7];
	while(true)
	{
		bool endcase=true;
		for(int i=1; i<=6; ++i)
		{
			cin>>b[i];
			if(b[i]) endcase=false;
		}
		if(endcase) break;

		int parcels=b[6];
		parcels+=b[5];
		b[1]=max(0,b[1]-b[5]*11);
		parcels+=b[4];
		int temp=b[2];
		b[2]=max(0,b[2]-b[4]*5);
		if(b[2]==0)
		{
			b[1]=max(0,b[1]-(b[4]*5-temp)*4);
		}
//		cout<<b[1]<<" "<<b[2]<<endl;	
		parcels+=ceil((float)b[3]/4);
		if(b[3]%4==1)
		{
			b[1]=max(0, b[1]-7);
			temp=b[2];
			b[2]=max(0,b[2]-5);
			if(b[2]==0)
				b[1]=max(0,b[1]-4*(5-temp));
		}
		else if(b[3]%4==2)
		{
			b[1]=max(0,b[1]-6);
			temp=b[2];
			b[2]=max(0,b[2]-3);
			if(b[2]==0)
				b[1]=max(0,b[1]-4*(3-temp));
		}
		else if(b[3]%4==3)
		{
			b[1]=max(0,b[1]-5);
			temp=b[2];
			b[2]=max(0,b[2]-1);
			if(b[2]==0)
				b[1]=max(0,b[1]-4*(1-temp));
		}
//		cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<endl;
		if(b[2])
		{
			parcels+=ceil((float)b[2]/9);
			if(b[2]%9!=0)
				b[1]=max(0,b[1]-36+(b[2]%9)*4);
		}
//		cout<<b[1]<<endl;
		parcels+=ceil((float)b[1]/36);
		cout<<parcels<<endl;
	}
}