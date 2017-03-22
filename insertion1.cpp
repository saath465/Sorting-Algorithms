#include<iostream>
#include<fstream>
using namespace std;


class insert
{
public:
	void insertion(int ar[], int n)
	{
		int i, j, key;
		for(i=1; i<n; i++)
		{
			key = ar[i];
			j = i-1;
			
			//sorting the array
			while(j>=0 && ar[j]>key)
			{
				ar[j+1] = ar[j];
				j = j-1;
			}
			ar[j+1] = key;
		}
		/*cout<<"Final list is::"<<endl;
		for(int k=0; k<n; k++)
		{
			cout<<ar[k]<<"\t";
		}*/
	}

};

int printdata(int arr[], int n)
{
	ofstream ofile;
	ofile.open("out.txt");
	for(int i=0; i<n; i++)
	{
		ofile<<arr[i]<<endl;
	}
	cout<<endl;
}

int main()
{
	int in, max; 
	ifstream rfile;
	rfile.open("input.txt");
	rfile>>max;
	int *arr = new int[max];
	int i=0;
	while(rfile>>in)
	{
		arr[i] = in;
		i++;
	}
	//cout<<"unsorted items are::"<<endl;
	//printdata(arr, max);
	//int arr[] = {78, 89, 56, 23, 12, 8, 0};
	//int max = sizeof(arr)/sizeof(arr[0]);
	insert I;
	I.insertion(arr, max);
	//cout<<"sorted items are::"<<endl;
	printdata(arr, max);
	return 0;
}
