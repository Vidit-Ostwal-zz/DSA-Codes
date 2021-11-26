/* Backtracking two different approach we have to mark the current cell as false in both the condition
1> Boolean vector passed as just a value, so we don't need to change it again to true as the changes will never be reflected 
2> Boolean vector passed as pointer we need to add a arguement to change the cell again to true value << Thing what will happen when it's just a cell away from the (2,2) cell)
*/
---------------------------------------------------------------------------------------------------------------------------;
// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>

// Maze obstacles as 2D vector  
// vector is passed without a pointer easy, the position we are in, mark that as false so that we don't retract that same path in next recursion.

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
    boolean[rows][columns] = false;
    if (rows < (boolean.size()-1))
    {
        number_of_ways(rows+1,columns,temp+'D',answer,boolean);
    }
    if (columns < (boolean[0].size()-1))
    {
        number_of_ways(rows,columns+1,temp+'R',answer,boolean);
    }
    if (rows >0)
    {
        number_of_ways(rows-1,columns,temp+'U',answer,boolean);
    }
    if (columns > 0)
    {
        number_of_ways(rows,columns-1,temp+'R',answer,boolean);
    }
}

int main() {
    vector<string> answer;
    vector<vector<bool>> boolean = {{true,true,true},{true,true,true},{true,true,true}};
    number_of_ways(0,0,"",answer,boolean);
    print(answer);
}


----------------------------------------------------------------------------------------------------------------------------------;
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

void number_of_ways(int rows,int columns,string temp,vector<string> &answer,vector<vector<bool>> &boolean)
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
    boolean[rows][columns] = false;
    if (rows < (boolean.size()-1))
    {
        number_of_ways(rows+1,columns,temp+'D',answer,boolean);
    }
    if (columns < (boolean[0].size()-1))
    {
        number_of_ways(rows,columns+1,temp+'R',answer,boolean);
    }
    if (rows >0)
    {
        number_of_ways(rows-1,columns,temp+'U',answer,boolean);
    }
    if (columns > 0)
    {
        number_of_ways(rows,columns-1,temp+'R',answer,boolean);
    }
    boolean[rows][columns] = true;
}

int main() {
    vector<string> answer;
    vector<vector<bool>> boolean = {{true,true,true},{true,true,true},{true,true,true}};
    number_of_ways(0,0,"",answer,boolean);
    print(answer);
}
