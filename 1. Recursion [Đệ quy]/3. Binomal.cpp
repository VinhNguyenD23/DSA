#include <iostream>

int bino(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    return bino(n - 1, k - 1) + bino(n - 1, k);
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::cout << bino(n, k);
}