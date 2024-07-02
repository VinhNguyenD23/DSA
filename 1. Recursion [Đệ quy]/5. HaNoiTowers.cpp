#include <iostream>

int i = 0;

template <typename T>
void move(int n, T start, T end, T spare)
{
    if (n == 1)
    {
        std::cout << "Move disk from " << start << " to " << end << std::endl;
        i++;
        return;
    }
    else
    {
        move(n - 1, start, spare, end);
        move(1, start, end, spare);
        move(n - 1, spare, end, start);
    }
}

int main()
{
    int disks;
    std::cin >> disks;
    move(disks, "A", "C", "B");
    std::cout << "Total move: " << i << std::endl;
}