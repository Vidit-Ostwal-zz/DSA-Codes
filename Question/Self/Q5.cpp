// Online C++ compiler to run C++ program online
#include <iostream>

int number_of_ways(int rows,int columns)
{
    if (rows == 1 || columns == 1)
    {
        return 1;
    }
    return number_of_ways(rows-1,columns) + number_of_ways(rows,columns-1);
}

int main() {
    int answer = number_of_ways(4,4);
    std::cout << answer;
}
