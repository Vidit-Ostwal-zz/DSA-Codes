class Solution {
public:
  void print(vector<vector<bool>> boolean)
  {
    for(int i = 0; i < boolean.size(); i++)
    {
      for (int j = 0; j < boolean[0].size();j++)
           {
             cout << boolean[i][j] << " " ;
           }
    cout << endl;
    }
  }
           
  string get_temp(int index, int n)
  {
    string temp="";
    for (int i = 0; i < n; i++)
    {
      if (i != index)
      {
         temp+='.'; 
      }
      else
      {
        temp+='Q';
      }
    }
    return temp;
  }
  
  vector<vector<bool>> make_path(int n)
  {
    vector<bool> bool_vector;
    for (int i = 0;i < n;i++)
    {
      bool_vector.push_back(true);
    }
    vector<vector<bool>> bool_vector1;
    for (int i = 0;i < n;i++)
    {
      bool_vector1.push_back(bool_vector);
    }
    return bool_vector1;
  }
  
  vector<vector<bool>> get_updated_path(vector<vector<bool>> path,int row, int column,int n)
  {
    for (int i = 0; i< n; i++)
    {
      path[row][i] = false;
    }
    for (int i = 0; i< n; i++)
    {
      path[i][column] = false;
    }
    int row1 = row;
    int column1 =column;
    while(row != (n-1) && column != (n-1))
    {
      path[row+1][column+1] = false;
      row++;
      column++;
    }
    while(row1 != (n-1) && column1 != 0)
    {
      path[row1+1][column1-1] = false;
      row1++;
      column1--;
    }
    return path;
  }
  
   void get_all_combinations (int n,vector<string> temp,int row, int column,vector<vector<bool>> path, vector<vector<string>>& final_vector,int N)
  {
    if(n == 0)
    {
      final_vector.push_back(temp);
      return ;
    }
    for (int i = 0; i < N;i++)
    {
      if (path[row][i])
      {
        string tempo = get_temp(i,N);
        temp.push_back(tempo);
        vector<vector<bool>> temp_path = get_updated_path(path,row,i,N);
        get_all_combinations (n-1,temp,row+1,i,temp_path,final_vector,N);
        temp.pop_back();
      }
    }
  }
  
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> final_vector;
      vector<vector<bool>> path = make_path(n);
        get_all_combinations(n,{},0,0,path, final_vector,n);
      return final_vector;
    }
};