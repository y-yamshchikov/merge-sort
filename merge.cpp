#include <iostream>

void merge_sort(int *a, int *w, int num);
void merge_sort_helper(int *a, int start, int end, int* b);
void merge(int *a, int start, int mid, int end, int *b);
void copy_array(int *a, int *b, int num);
void print_array(int *a, int num);

#define NUM 10
int work_array[NUM];

int main (int argc, char *argv[])
{
	int array[NUM]={4,1,5,4,5,1,7,5,2,8};

	merge_sort(array, work_array, NUM);
	print_array(array, NUM);

	return 0;
}


void merge_sort(int *a, int *w, int num)
{
	copy_array(a, w, num);
	merge_sort_helper(a, 0, num, w);
}

void merge_sort_helper(int *a, int start, int end, int* b)
{
	if (end-start < 2)
	{
		return;
	}

	int mid = (start+end)/2;

	merge_sort_helper(b, start, mid, a);
	merge_sort_helper(b, mid, end, a);

	merge(a, start, mid, end, b);
}

void merge(int *a, int start, int mid, int end, int *b)
{
	int j = start;
	int k = mid;

	for (int i = start; i < end; i++)
	{
		if (j < mid && (k >= end || b[j]<=b[k]))
		{
			a[i] = b[j++];
		}
		else
		{
			a[i] = b[k++];
		}
	}
}

void copy_array(int *a, int *b, int num)
{
	for (int i = 0; i < num; i++)
	{
		b[i] = a[i];
	}
}

void print_array(int *a, int num)
{
	for (int i = 0; i < num; i++)
	{
		std::cout<<a[i]<<" ";
	}

	std::cout<<std::endl;
}
