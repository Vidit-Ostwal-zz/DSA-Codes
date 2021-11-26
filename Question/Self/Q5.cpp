/* Idea is that whenever it hits edge of the matrix after that only one way to go so taht makes it a base condition 
Here 5,5 to 1,1 and base condition when it hits 1,1 
In this person can go only right or down.*/


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
