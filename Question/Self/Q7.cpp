// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>

/* Maze with obstacle lets say 3,3 matrix with river at 2,2 and no diagonal movement*/
/* Adding some more base conditions that's all */
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
    if (rows == 2 && columns == 2)
    {
        return;
    }
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
   
}

int main() {
    vector<string> answer;
    number_of_ways(3,3,"",answer);
    print(answer);
}



--------------------------------------------------------------------------------------------------------------------;
// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>

/* Maze with obstacle lets say 3,3 matrix with river at 2,2 and no diagonal movement*/
/* Adding some more base conditions that's all */
using namespace std;
void print(vector<string> answer)
{
    cout << answer.size()<<endl;
    for (int i =0 ; i < answer.size();i++)
    {
        cout << answer[i]<< endl;
    }
}

void number_of_ways(int rows,int columns,string temp,vector<string> &answer,vector<vector<bool>> boolean)
{
    if (!boolean[rows][columns])
    {
        return;
    }
    if (rows == (boolean.size()-1) && columns == (boolean[0].size()-1))
    {
        answer.push_back(temp);
        return ;
    }
    
    if (rows < (boolean.size()-1))
    {
        number_of_ways(rows+1,columns,temp+'D',answer,boolean);
    }
    if (columns < (boolean[0].size()-1))
    {
        number_of_ways(rows,columns+1,temp+'R',answer,boolean);
    }
   
}

int main() {
    vector<string> answer;
    vector<vector<bool>> boolean = {{true,true,true},{true,false,true},{true,true,true}};
    number_of_ways(0,0,"",answer,boolean);
    print(answer);
}
