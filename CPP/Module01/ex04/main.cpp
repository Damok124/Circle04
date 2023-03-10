#include <iostream>

void increment(int& x)
{
    x++;
}

int main()
{
    int y = 5;
    increment(y);
    std::cout << y << std::endl; // affiche 6
    return 0;
}
