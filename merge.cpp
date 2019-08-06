#include <iostream>

void merge_sort(int *A, int *W, size_t size);
void merge_helper(int *A, size_t start, size_t end, int *B);
void merge(int *A, size_t start, size_t mid, size_t end, int *B);
void copy_array(int *src, int *dst, size_t size);
void print_array(int *A, size_t size);


int STORAGE[256000];

int main (int argc, char *argv[])
{
	int A[] = {3234,452342,34523,453,56473,5456,34563,4532423,462,7654,3,4563,6,53564563,5345,646,745,6,423435};
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

	size_t mid = (start+end)/2;

	merge_helper(B, start, mid, A);
	merge_helper(B, mid, end, A);
	merge(A, start, mid, end, B);
}

void merge(int *A, size_t start, size_t mid, size_t end, int *B)
{
	size_t j = start;
	size_t k = mid;

	for(size_t i = start; i < end; ++i)
	{
		if(j < mid && (k >= end || B[j] < B[k]))
		{
			A[i] = B[j++];
		}
		else
		{
			A[i] = B[k++];
		}
	}
}
void copy_array(int *src, int *dst, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		dst[i] = src[i];
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

