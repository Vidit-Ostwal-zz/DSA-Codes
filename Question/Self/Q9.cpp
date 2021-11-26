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

void print_path(vector<vector<int>> path)
{
    for (int i =0 ; i < path.size();i++)
    {
        for(int j = 0;j < path[i].size();j++)
        {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
}
void number_of_ways(int rows,int columns,string temp,vector<string> &answer,vector<vector<bool>> boolean,vector<vector<int>> path,int step)
{
    if (!boolean[rows][columns])
    {
        return;
    }
    if (rows == (boolean.size()-1) && columns == (boolean[0].size()-1))
    {
        path[rows][columns] = step;
        print_path(path);
        cout << temp << endl;
        cout << endl;
        answer.push_back(temp);
        return ;
    }
    boolean[rows][columns] = false;
    path[rows][columns] = step;
    if (rows < (boolean.size()-1))
    {
        number_of_ways(rows+1,columns,temp+'D',answer,boolean,path,step+1);
    }
    if (columns < (boolean[0].size()-1))
    {
        number_of_ways(rows,columns+1,temp+'R',answer,boolean,path,step+1);
    }
    if (rows >0)
    {
        number_of_ways(rows-1,columns,temp+'U',answer,boolean,path,step+1);
    }
    if (columns > 0)
    {
        number_of_ways(rows,columns-1,temp+'L',answer,boolean,path,step+1);
    }
    
}

int main() {
    vector<string> answer;
    vector<vector<bool>> boolean = {{true,true,true},{true,true,true},{true,true,true}};
    vector<vector<int>> path ={{0,0,0},{0,0,0},{0,0,0}};
    number_of_ways(0,0,"",answer,boolean,path,1);
}
