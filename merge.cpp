#include <iostream>

void merge_sort(int *A, int *W, size_t num);
void merge_helper(int *A, size_t start, size_t end, int *B);
void merge(int *A, size_t start, size_t mid, size_t end, int *B);
void copy_array(int *src, int *dst, size_t num);
void print_array(int *A, size_t num);

int SPACE[256000];

int main(int argc, char *argv[])
{
	int arr[] = {3245,76785,2,425,456,455,845,63,4,34,56,646,7598856,9,546,3,543};
	size_t size = sizeof(arr)/sizeof(arr[0]);
	
	print_array(arr, size);
	merge_sort(arr, SPACE, size);
	print_array(arr, size);

	return 0;
}

void merge_sort(int *A, int *W, size_t num)
{
	copy_array(A, W, num);
	merge_helper(A, 0, num, W);
}

void merge_helper(int *A, size_t start, size_t end, int *B)
{
	if (end - start < 2)
	{
		return;
	}

	size_t mid = (start + end)/2;

	merge_helper(B, start, mid, A);
	merge_helper(B, mid, end, A);
	merge(A, start, mid, end, B);
}

void merge(int *A, size_t start, size_t mid, size_t end, int *B)
{
	size_t j = start;
	size_t k = mid;

	for (size_t i = start; i < end; ++i)
	{
		if (j < mid && (k >= end || B[j] <= B[k]))
		{
			A[i] = B[j++];
		}
		else
		{
			A[i] = B[k++];
		}
	}
}

void copy_array(int *src, int *dst, size_t num)
{
	for (size_t i = 0; i < num; ++i)
	{
		dst[i] = src[i];
	}
}

void print_array(int *A, size_t num)
{
	for (size_t i = 0; i < num; ++i)
	{
		std::cout<<A[i]<<" ";
	}
	std::cout<<std::endl;
}
