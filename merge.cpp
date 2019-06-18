#include <iostream>

void merge_sort(int *A, int *W, size_t num);
void merge_helper(int *A, size_t start, size_t end, int *B);
void merge(int *A, size_t start, size_t mid, size_t end, int *B);
void copy_array(int *A, int *B, size_t num);
void print_array(int *A, size_t num);

int STORAGE[256000];

int main(int argc, char *argv[])
{
	int arr[] = {2342,554,3,23,5452,234,333,2,5542,2,333,3,2,134123,3,5,456734324,422,22,2,2,141234};
	size_t size = sizeof(arr)/sizeof(int);

	print_array(arr, size);
	merge_sort(arr, STORAGE, size);
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

	size_t mid = (start+end)/2;

	merge_helper(B, start, mid, A);
	merge_helper(B, mid, end, A);
	merge(A, start, mid, end, B);
}

void merge(int *A, size_t start, size_t mid, size_t end, int *B)
{
	size_t j = start;
	size_t k = mid;
	for (size_t i = start; i < end; i++)
	{
		if (j < mid && (k >= end || B[j]<=B[k]))
		{
			A[i] = B[j++];
		}
		else
		{
			A[i] = B[k++];
		}
	}
}

void copy_array(int *A, int *B, size_t num)
{
	for (size_t i = 0; i < num; i++)
	{
		B[i] = A[i];
	}
}

void print_array(int *A, size_t num)
{
	for(size_t i = 0; i < num; i++)
	{
		std::cout<<A[i]<<" ";
	}
	std::cout<<std::endl;
}
