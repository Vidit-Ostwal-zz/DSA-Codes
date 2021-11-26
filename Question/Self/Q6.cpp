// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;

int number_of_ways(int rows,int columns,string temp)
{
    if (rows == 1 || columns == 1)
    {
        while (rows != 1)
        {
            temp += 'd';
            rows--;
        }
        while (columns != 1)
        {
            temp += 'r';
            columns--;
        }
        std::cout<<temp << endl;
        
        return 1;
    }
    return number_of_ways(rows-1,columns,temp+'d') + number_of_ways(rows,columns-1,temp+'r');
}

int main() {
    int answer = number_of_ways(3,3,"");
    std::cout << answer;
}
