#include<iostream>
#include<fstream>

using namespace std;

int shell(int sh[], int n)
{
	int i, interval, outer, inner;
	i =0;
	//setup the interval
	interval = 1;
	while(interval <= n/3)
	{
		interval = interval * 3 + 1;	//knuths formula
	}
	
	while(interval > 0)
	{
		
		for(outer = interval; outer<n; outer++)
		{
			int value  = sh[outer];
			inner = outer;
			while(inner > interval -1 && sh[inner - interval] >= value)
			{
				sh[inner] = sh[inner - interval];			//swap values
				inner = inner - interval;
			}
			sh[inner] = value;			//value swapped at the place
		}
		interval = (interval-1)/3;
		i++;
	}
	
	return i;
}



int main()
{
	ifstream infile;
	infile.open("input.txt");
	int size_e;
	infile>>size_e;
	int *input = new int[size_e];
	int data;
	int i = 0;
	while(infile>>data)
	{
		input[i] = data;		//read input
		i++;
	}
	clock_t begin = clock();
	int count = shell(input, size_e);
	clock_t end = clock();
	double tot_time = (double)(end - begin) *1000 / CLOCKS_PER_SEC;
	ofstream outfile;
	outfile.open("out_shell.txt");
	outfile<<"sorted list is ::"<<endl;
	outfile<<"total iterations is::"<<count<<endl;
	for(int k=0; k<size_e; k++)
	{
		outfile<<input[k]<<"\t";		//write output
	}
	outfile<<"Total time taken::"<<tot_time<<endl;
	outfile.close();
	infile.close();
	return 0;
}

