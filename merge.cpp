#include <iostream>

void merge_sort(int *A, int *W, int num);
void merge_helper(int *A, int start, int end, int *B);
void merge(int *A, int start, int mid, int end, int *B);
void copy_array(int *A, int *B, int num);
void print_array(int *A, int num);

int STORAGE[256000];

int main(int argc, char *argv[])
{
	int arr[] = {33,2,5,3,33,5,134,3,44,3,3,3,5,3,31,1,7,8,8,3,4,2,3,44};
	int size = sizeof(arr)/sizeof(int);

	merge_sort(arr, STORAGE, size);
	print_array(arr, size);

	return 0;
}

void merge_sort(int *A, int *W, int num)
{
	copy_array(A, W, num);
	merge_helper(A, 0, num, W);
}

void merge_helper(int *A, int start, int end, int *B)
{
	if (end - start < 2)
	{
		return;
	}

	int mid = (end+start)/2;

	merge_helper(B, start, mid, A);
	merge_helper(B, mid, end, A);

	merge(A, start, mid, end, B);
}

void merge(int *A, int start, int mid, int end, int *B)
{
	int j = start;
	int k = mid;
	for (int i = start; i < end; i++)
	{
		if (j < mid && (k >= end || B[j]<=B[k] ))
		{
			A[i] = B[j++];
		}
		else
		{
			A[i] = B[k++];
		}
	}
}

void copy_array(int *A, int *B, int num)
{
	for (int i = 0; i < num; i++)
	{
		B[i] = A[i];
	}
}

void print_array(int *A, int num)
{
	for (int i = 0; i < num; i++)
	{
		std::cout<<A[i]<<" ";
	}
	std::cout<<std::endl;
}
