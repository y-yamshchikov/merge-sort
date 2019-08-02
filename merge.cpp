#include <iostream>

void merge_sort(int *A, int *W, size_t size);
void merge_helper(int *A, size_t start, size_t end, int *B);
void merge(int *A, size_t start, size_t mid, size_t end, int *B);
void print_array(int *A, size_t size);
void copy_array(int *src, int *dst, size_t size);

int STORAGE[256000];

int main(int argc, char* argv[])
{
	int A[] = {4352,243,2,34243,523,4,42,3,5667857,6,3,4,52,324,3423645,87586,96798,76,45,63,452,4,65};

	size_t size = sizeof(A)/sizeof(A[0]);

	print_array(A, size);
	merge_sort(A, STORAGE, size);
	print_array(A, size);

	return 0;
}

void merge_sort(int *A, int *W, size_t size)
{
	copy_array(A, W, size);
	merge_helper(A, 0, size, W);
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

void print_array(int *A, size_t size)
{
	for(size_t i = 0; i < size; ++i)
	{
		std::cout<<A[i]<<" ";
	}
	std::cout<<std::endl;
}

void copy_array(int *src, int *dst, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		dst[i] = src[i];
	}
}
