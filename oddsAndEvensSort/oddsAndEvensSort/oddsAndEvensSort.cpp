#include <iostream>
#include <time.h>
using namespace std;
const int n = 1000;
int a[n] = {};
int phase;
int i;
void getRandom();
void doSort();
void swap();

int main()
{
	getRandom();
	doSort();
	
	return 0;
}
void getRandom()
{
	srand (time(NULL));
	for(int i=0; i < n; i++)
	{
		a[i] = rand() % 1000 + 1;
		cout << a[i] << endl;
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
				}
			}
		}
	}

}
void swap(int swapFrom[],int swapTo[])
{
	//this function isnt correct
	int temp=swapFrom[i];
	swapFrom[i]=swapTo[i];
	swapTo[i]=temp;

}