#include <iostream>
#include <stdlib.h>
//#include
//int arr[100];
using namespace std;

int n;

void merge(int A[], int l, int m, int h)
{
	int i, j, k;
	int n1 = m-l+1;	
	int n2 = h-m;
	int *L = new int[n1];
	int *H = new int[n2];

	//copy the contents of the array into a temp array
	for(i=0; i<n1; i++)
		L[i] = A[l+i];
	for(j=0; j<n2; j++)
		H[j] = A[m+1+j];
	//initialize the values for sorting
	i = 0;
	j = 0;
	k = l;

	while(i<n1 && j<n2)
	{
		if(L[i] <= H[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = H[j];
			j++;
		}
		k++;
	}

	//copy all contents from L
	while(i<n1)
	{
		A[k] = L[i];
		i++;
		k++;
	}

	//copy all the contents from H
	while(j<n2)
	{
		A[k] = H[j];
		k++;
		j++;
	}
}
void mergesort(int A[], int low, int high)
{
	cout<<"here";
	cout<<"low"<<low;
	cout<<"high"<<high;
	cout<<endl;
	if(low < high)
	{
		int mid = (low+(high-1))/2;
		//sort the sub arrays
		mergesort(A, low, mid);
		mergesort(A, mid+1, high);

		merge(A, low, mid, high);
	}
}
void printdata(int A[], int size)
{
	cout<<"The sorted array is::"<<endl;
	for(int i=0; i<size; i++)
	{
		cout<<A[i]<<"\t";
	}
}

int main()
{
	int i;
		
	//cout<<"Enter the number of items to sort"<<endl;
	//cin>>n;
	int A[] = {23, 12, 8, 56, 7};
	//cout<<"Enter the array elements for sorting"<<endl;
	/*for(i=0; i<n; i++)
	{
		cin>>A[i];
	}*/
	int max = sizeof(A)/sizeof(A[0]);
	for(i=0; i<max; i++)
	{
		cout<<A[i];
		cout<<"\t";
	}
	cout<<endl;
	
	//call the mergesort
	mergesort(A, 0, max-1);
	for(i=0; i<n; i++)
	{
		cout<<A[i];
	}
	return 0;
}


