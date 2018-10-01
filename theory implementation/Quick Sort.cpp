#include<iostream>
using namespace std;

int n=5;

int partition(int arr[], int l, int r)
{
	int temp[r-l+1];
	int L,R, i;
	for(i=l, L=0, R=r-l; i<r; ++i)
	{
		if(arr[i]<arr[r]) //arr[r]->pivot
		{
			temp[L++]=arr[i];
		}
		else
			temp[R--]=arr[i];
	}
	temp[L]=arr[r];
	for(i=0; i<r-l+1; ++i)
	{
		arr[i+l]=temp[i];
	}
	return L;
}

void quick_sort(int arr[], int l, int r)
{
	if(l<r)
	{
		int p=partition(arr,l,r);
//		cout<<p<<endl;
		quick_sort(arr,l,p-1);
		quick_sort(arr,p+1,r);
	}
}

int main()
{
	int arr[n]={5,2,9, 4, 7};
	quick_sort(arr, 0, n-1);
	for(int i=0; i<n; ++i )
		cout<<arr[i]<<" ";
	cout<<endl;
}