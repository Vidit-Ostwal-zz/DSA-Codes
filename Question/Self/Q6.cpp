// Online C++ compiler to run C++ program online
// Different Approaches

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


-----------------------------------------------------------------------------------------------;
// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void print(vector<string> answer)
{
    for (int i =0 ; i < answer.size();i++)
    {
        cout << answer[i]<< endl;
    }
}

vector<string>  number_of_ways(int rows,int columns,string temp)
{
    if (rows == 1 || columns == 1)
    {
        while (rows != 1)
        {
            temp += 'D';
            rows--;
        }
        while (columns != 1)
        {
            temp += 'R';
            columns--;
        }
        vector<string> final_vector;
        final_vector.push_back(temp);
        return final_vector;
    }
    
    vector<string> temp_answer1 = number_of_ways(rows-1,columns,temp+'D');
    vector<string> temp_answer2 = number_of_ways(rows,columns-1,temp+'R');
    temp_answer1.insert(temp_answer1.end(),temp_answer2.begin(),temp_answer2.end());
    return temp_answer1;
}

int main() {
    vector<string> answer = number_of_ways(3,3,"");
    print(answer);
}



----------------------------------------------------------------------------------------;
// Online C++ compiler to run C++ program online
/* Another way when base condition is of both row and column 1-1, here condtion are made over the recursive calls*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void print(vector<string> answer)
{
    for (int i =0 ; i < answer.size();i++)
    {
        cout << answer[i]<< endl;
    }
}

void number_of_ways(int rows,int columns,string temp,vector<string> &answer)
{
    if (rows == 1 || columns == 1)
    {
        while (rows != 1)
        {
            temp += 'D';
            rows--;
        }
        while (columns != 1)
        {
            temp += 'R';
            columns--;
        }
       
        answer.push_back(temp);
        return ;
    }
    
    number_of_ways(rows-1,columns,temp+'D',answer);
    number_of_ways(rows,columns-1,temp+'R',answer);
   
}

int main() {
    vector<string> answer;
    number_of_ways(4,3,"",answer);
    print(answer);
}

---------------------------------------------------------------------------------------------------------------------;
// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void print(vector<string> answer)
{
    cout << answer.size()<<endl;
    for (int i =0 ; i < answer.size();i++)
    {
        cout << answer[i]<< endl;
    }
}

void number_of_ways(int rows,int columns,string temp,vector<string> &answer)
{
    if (rows == 1 && columns == 1)
    {
        answer.push_back(temp);
        return ;
    }
    
    if (rows>1)
    {
        number_of_ways(rows-1,columns,temp+'D',answer);
    }
    if (columns > 1)
    {
        number_of_ways(rows,columns-1,temp+'R',answer);
    }
    if (columns > 1 && rows > 1)
    {
        number_of_ways(rows-1,columns-1,temp+'d',answer);
    }
   
}

int main() {
    vector<string> answer;
    number_of_ways(4,3,"",answer);
    print(answer);
}

