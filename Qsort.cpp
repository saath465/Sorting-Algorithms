#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

std::vector<int> input;
int size_e;

class quicksort
{
private:

	int swap(int lpp, int rpp)
	{
		//cout<<"Swapping"<<endl;
		int temp = input[lpp];
		input[lpp] = input[rpp];
		input[rpp] = temp;
	}

	int partition(int low, int high)
	{
		//cout<<"parti"<<endl;
		int lp = (low-1);
		int pivot = input[high];
		for(int j = low; j <= high-1; j++)
		{
			if(input[j] <= pivot)
			{
				lp++;
				swap(lp, j);
			}
		}
		swap((lp+1), high);
		return(lp+1);
	}

public:
	int qsort(int l, int h)
	{
		//cout<<"Q-sort"<<endl;
		if(l < h)
		{
			
			int part = partition(l, h);
			qsort(l, part-1);
			qsort(part+1, h);
		}
		
		return 0;
	}
};

int main()
{
	quicksort Q;
	ifstream infile;
	infile.open("input.txt");
	infile>>size_e;
	//cout<<"enter Size:";
	//cin>>size_e;
	int data;
	while(infile>>data)
	{
		input.push_back(data);
	}
	//max = sizeof(input)/sizeof(input[0]);
	clock_t start = clock();
	Q.qsort(0, size_e-1);
	clock_t stop = clock();
	double total_time = (double)(stop - start) * 1000 / CLOCKS_PER_SEC;
	ofstream outfile;
	outfile.open("out_qsort.txt");
	for(int k=0; k<size_e; k++)
	{
		outfile<<input[k]<<"\t";
	}
	outfile<<total_time<<endl;
	infile.close();
	outfile.close();
	return 0;
}
	

			
		
		
		
		
	
