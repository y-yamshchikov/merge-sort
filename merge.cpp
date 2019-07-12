#include <iostream>

void merge_sort(int *A, int *W, size_t num);
void merge_helper(int *A, size_t start, size_t end, int *B);
void merge(int *A, size_t start, size_t mid, size_t end, int *B);
void copy_array(int *src, int *dst, size_t num);
void print_array(int *A, size_t num);

int W[256000];
int main (int argc, char *argv[])
{

	int N[] = {234254,25,3,543,54,3,245234,5234,5,2345,345,234,5,24352342,57,67,3,4,13,5,7,578,277,67,6,936,33,5,6,3456};
	size_t n = sizeof(N)/sizeof(N[0]);

	print_array(N, n);
	merge_sort(N,W,n);
	print_array(N, n);

	return 0;
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

	size_t mid = (start + end)/2;

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

void copy_array(int *src, int *dst, size_t num)
{
	for (int i = 0; i < num; ++i)
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
