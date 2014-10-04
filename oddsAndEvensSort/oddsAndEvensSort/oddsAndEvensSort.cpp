#include <iostream>
#include <time.h>
#include <fstream>
#include <omp.h>
using namespace std;
void getRandom();
void doSort();
void swap();
void doPrint();


const int n = 100000;
int a[n] = {};
int phase;
int i;
int threadCount;
int tmp;

int main()
{
	for(threadCount=1;threadCount<=10;threadCount++);
	{
		clock_t start,end;
		srand(time(0));
		ofstream myfile;
		myfile.open ("stats.txt", ios::app);

		float clockDiff =0.0;
		getRandom();
		start = clock();
		//doPrint();
		doSort();
		//doPrint();
		end = clock();
		clockDiff = (float)((end - start)/CLOCKS_PER_SEC);
		cout << "Array is Sorted, it took " << clockDiff <<" seconds" << endl;
		myfile << "It took " << clockDiff << " seconds to run with two parallel for directives on " << threadCount << " threads" << endl;
	}
	system("pause");
	return 0;
}
void doPrint()
{
	cout << endl;
	for(int i=0; i < n; i++)
	{
		cout << a[i] << endl;
	}
}
void getRandom()
{
	
	for(int i=0; i < n; i++)
	{
		a[i] = rand() % 1000 + 1;
		//cout << a[i] << endl;
	}
}
void doSort()
{
	for(phase =0; phase < n; phase++)
	{
	
		if(phase % 2 == 0)
		{
#pragma omp parallel for num_threads(threadCount)\
	default(none) shared(a,n) private(i,tmp)
			for(i=1;i<n;i+=2)
			{
				if(a[i-1] > a[i])
				{
					tmp=a[i-1];
					a[i-1]=a[i];
					a[i]=tmp;
					//cout << "swapped" << endl;
				}
			}
		}
		else
		{
			for(i=1; i<n-1;i+=2)
			{
				if(a[i] > a[i+1])
				{
					tmp=a[i+1];
					a[i+1] =a[i];
					a[i]=tmp;
					//cout << "swapped" << endl;
				}
			}
		}
		
	}

}
//void swap(int swapFrom[],int swapTo[])
//{
//	//this function isnt correct
//	int temp=swapFrom[i];
//	swapFrom[i]=swapTo[i];
//	swapTo[i]=temp;
//
//}