#include <iostream>

int BinarySearch(int A[], int start, int finish, int k)
{
    int mid = start + (finish - start) / 2;
    if (start > finish)
        return -1;
    if (k == A[mid])
        return mid;
    else if (k < A[mid])
        return BinarySearch(A, start, mid - 1, k);
    else
        return BinarySearch(A, mid + 1, finish, k);
}

int main()
{
    int A[] = {1, 2, 5, 7, 11, 23, 35, 67};
    int n;
    std::cin >> n;
    std::cout << BinarySearch(A, 0, sizeof(A) / sizeof(int) - 1, n);
}