#include <iostream>

void merge_sort(int *A, int *W, int num);
void merge_helper(int *A, int start, int end, int *B);
void merge(int *A, int start, int mid, int end, int *B);
void copy_array(int *A, int *B, int num);
void print_array(int *A, int num);

int STORAGE[256000];

int main(int argc, char *argv[])
{
	int arr[] = {3,5,22,1,5,5,3,2,2,3,33,51,77775,42,4,888,24624,42,7,4,2};
	int size = sizeof(arr)/sizeof(int);

	print_array(arr, size);
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

	int mid = (start + end)/2;

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
		if (j < mid && (k >= end || B[j] <= B[k]) )
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
