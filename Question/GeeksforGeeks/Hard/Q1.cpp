#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> make_path (int row,int column)
{
    vector<bool> temp_bool ;
    vector<vector<bool>> final_bool;
    for (int i = 0; i < column;i++)
    {
        temp_bool.push_back(true);
    }
    for (int j = 0; j < row;j++)
    {
        final_bool.push_back(temp_bool);
    }
    return final_bool;
}

vector<vector<char>> show_path (int row,int column)
{
    vector<char> temp_bool ;
    vector<vector<char>> final_bool;
    for (int i = 0; i < column;i++)
    {
        temp_bool.push_back('A');
    }
    for (int j = 0; j < row;j++)
    {
        final_bool.push_back(temp_bool);
    }
    return final_bool;
}

void print(vector<vector<char>> path)
{
    for (int i =0; i < path.size(); i++)
    {
        for (int j = 0; j < path[0].size();j++)
        {
            cout << path[i][j] << "  ";
        }
        cout << endl;
    }
    cout<< endl;
}

vector<vector<bool>> get_updated_path(vector<vector<bool>> path,int row,int column)
{
    if(row+2 < path.size() && column+1 < path[0].size())
    {
        path[row+2][column+1] = false;
    }
    if(row+2 < path.size() && column-1 >= 0 && column-1 < path[0].size())
    {
        path[row+2][column-1] = false;
    }
    if(row-2 >= 0 && row-2 < path.size() && column+1 < path[0].size())
    {
        path[row-2][column+1] = false;
    }
    if(row-2 >= 0 && row-2 < path.size() && column-1 >= 0 && column-1 < path[0].size())
    {
        path[row-2][column-1] = false;
    }
    if(row+1 < path.size() && column+2 < path[0].size())
    {
        path[row+1][column+2] = false;
    }
    if(row+1 < path.size() && column-2 >= 0 && column-2 < path[0].size())
    {
        path[row+1][column-2] = false;
    }
    if(row-1 >= 0 && row-1 < path.size() && column+2 < path[0].size())
    {
        path[row-1][column+2] = false;
    }
    if(row-1 >= 0 && row-1 < path.size() && column-2 >= 0 && column-2 < path[0].size())
    {
        path[row-1][column-2] = false;
    }
    return path;
}

void place_knights(vector<vector<bool>>path,int count_left,int &count,vector<vector<char>>show_path)
{
    if (count_left == 0)
    {
        count++;
        print(show_path);
    }
    
    for(int row_count = 0; row_count < path.size();row_count++)
    {
        for (int col_count = 0; col_count < path[0].size(); col_count++)
        {
            if (path[row_count][col_count])
            {
                show_path[row_count][col_count] = 'K';
                path[row_count][col_count] = false;
                vector<vector<bool>> temp_path = get_updated_path(path,row_count,col_count);
                place_knights(temp_path,count_left-1,count,show_path);
                show_path[row_count][col_count] ='A';
            }
        }
    }
}

int main() {
    int count = 0;
    place_knights(make_path(4,3),6,count,show_path(4,3));
    cout<< count;
}
