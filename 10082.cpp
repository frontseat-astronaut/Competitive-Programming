#include<bits/stdc++.h>
using namespace std;

int main()
{
	int pos[256]={0};
	char K[50]={'1','2','3','4','5','6','7','8','9','0','-','=',
					'Q','W','E','R','T','Y','U','I','O','P','[',']','\\',
					'A','S','D','F','G','H','J','K','L',';','\'',
					'Z','X','C','V','B','N','M',',','.','/'};
	for(int i=0; K[i]!='\0'; ++i)
	{
		pos[K[i]]=i+1;
	}
	char ch;
	while(scanf("%c",&ch)!=EOF)
	{
		if(pos[ch]!=0)
			cout<<K[pos[ch]-2];
		else
			cout<<ch;
	}
}