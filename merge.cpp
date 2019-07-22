#include <iostream>

void print_array(int *A, size_t num);
void copy_array(int *src, int *dst, size_t num);
void merge_sort(int *A, int *W, size_t num);
void merge_helper(int *A, size_t start, size_t end, int *B);
void merge(int *A, size_t start, size_t mid, size_t end, int *B);

int SPACE[240000];

int main(int argc, char *argv[])
{
	int A[] = {32345634,245234,53,45,23,452,345,356,34,56463,5423,53452,34534,56456,34,52345,3467,874,534,12,3345,34,6456,3,45243};
	size_t size = sizeof(A)/sizeof(A[0]);
	
	print_array(A, size);
	merge_sort(A, SPACE, size);
	print_array(A, size);

	return 0;
}

void print_array(int *A, size_t num)
{
	for (size_t i = 0; i < num; i++)
	{
		std::cout<<A[i]<<" ";
	}
	std::cout<<std::endl;
}

void copy_array(int *src, int *dst, size_t num)
{
	for (size_t i = 0; i < num; i++)
	{
		dst[i] = src[i];
	}
}

void merge_sort(int *A, int *W, size_t num)
{
	copy_array(A, W, num);
	merge_helper(A, 0, num, W);
}

void merge_helper(int *A, size_t start, size_t end, int *B)
{
	if ((end - start) < 2)
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
