#include<iostream>
using namespace std;

class bubblesort
{
	public:

	void swap(int *a, int *b)
	{
		int c = *a;
		*a = *b;
		*b = c;
	}

	int bubble(int arr[], int n)
	{
		int i,j;
		for(i=0; i<n-1; i++)
			for(j=0; j<n-i-1; j++)
				if(arr[j]>arr[j+1])
					swap(&arr[j], &arr[j+1]);
		cout<<"Final list after sorting is::"<<endl;
		for(int k=0; k<n; k++)
		{
			cout<<arr[k]<<"\t";
		}
	}
};

int main()
{
	int i, max;
	int arr[] = {3,10,0,1,5};
	max = sizeof(arr)/sizeof(arr[0]);
	bubblesort b;
	b.bubble(arr, max);
	return 0;
}



