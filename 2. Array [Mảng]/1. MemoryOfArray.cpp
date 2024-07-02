#include <iostream>

int main()
{
    int Array[] = {3, 5, 6, 7};
    std::cout << "Address\t\tContent\n";
    for (int i = 0; i < sizeof(Array) / sizeof(int); i++)
    {

        std::cout << (Array + i) << "\t" << *(Array + i) << std::endl;
    }
    std::cout << "=====Other array=====\n";
    int Array2[2][5] = {{1, 5, 6, 3, 7}, {2, 4, 3, 2, 5}};
    std::cout << "Address\t\tContent\n";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            std::cout << (*(Array2 + i) + j) << "\t" << *(*(Array2 + i) + j) << std::endl;
        }
    }
}