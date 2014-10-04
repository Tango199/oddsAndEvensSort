#include <iostream>
#include <time.h>
using namespace std;
void getRandom();
void doSort();
void swap();
void doPrint();


const int n = 100000;
int a[n] = {};
int phase;
int i;

int main()
{
	clock_t start,end;
	srand(time(0));

	float clockDiff =0.0;
	getRandom();
	start = clock();
	//doPrint();
	doSort();
	//doPrint();
	end = clock();
	clockDiff = (float)((end - start)/CLOCKS_PER_SEC);
	cout << "Array is Sorted, it took " << clockDiff <<" seconds" << endl;
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
			for(i=1;i<n;i+=2)
			{
				if(a[i-1] > a[i])
				{
					swap(a[i-1],a[i]);
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
					swap(a[i],a[i+1]);
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