#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;

void selection(int sel[], int n)
{
	int i, j, min;
	int swap_index = 0;
	for(i=0; i<n-1; i++)
	{
		min = i;
		for(j=i+1; j<n; j++)
		{
			if(sel[j] < sel[min])
			{
				min = j;
				swap_index = 1;
			}
		}
		if(swap_index == 1)
		{
			int temp = sel[i];
			sel[i] = sel[min];
			sel[min] = temp;
		}
	}
	
}

int main()
{
	int max;
	ifstream infile;
	infile.open("input.txt");
	infile>>max;
	int *input = new int[max];
	int data;
	int i = 0;
	while(infile>>data)
	{
		input[i] = data;
		i++;
	}
	clock_t begin = clock();
	selection(input, max);
	clock_t end = clock();
	double time_exec = (double)(end - begin)/CLOCKS_PER_SEC;
	ofstream outfile;
	outfile.open("output_select.txt");
	for(int k=0; k<max; k++)
	{
		outfile<<input[k]<<"\n";
	}
	outfile<<time_exec;
	outfile.close();
	infile.close();
	
	return 0;
}
