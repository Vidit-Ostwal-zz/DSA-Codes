class Solution {
public:
  /*Traversing through the whole matrix and for every 0 encountered,
  turn the rest of the element in that particular row/ column to some otehr negative value
  then again throguh full traversal changing them again back to 0*/
  void change_rest (vector<vector<int>>& matrix, int row, int column)
  {
    for (int i = 0; i < matrix.size();i++)
    {
      if (i != row && matrix[i][column]!= 0)
      {
        matrix[i][column] = -1;
      }
    }
    for (int j = 0; j < matrix[0].size();j++)
    {
      if (j != column)
      {
        matrix[row][j] = -1;
      }
    }
  }
  
  void brute_solution (vector<vector<int>>& matrix)
  {
    int row = matrix.size();
    int column = matrix[0].size();
    
    for (int i = 0; i < row;i++)
    {
      for (int j = 0; j < column ; j++)
      {
        if (matrix[i][j] == 0 && matrix[i][column]!= 0)
        {
          change_rest(matrix, i , j);
        }
      }
    }
    
    for (int i = 0; i < row;i++)
    {
      for (int j = 0; j < column ; j++)
      {
        if (matrix[i][j] == -1)
        {
          matrix[i][j] = 0;
        }
      }
    }
  }
  /*Time Complexity = O((N*M) * (N+M))
  Space Complexity = O(1)*/
  
  
  
  /*make two vector and 0 respective row and column as -1, then iterate and update*/
  void better_solution (vector<vector<int>>& matrix)
  {
    int row = matrix.size();
    int column = matrix[0].size();
    
    vector<int> row_vector(row,0);
    vector<int> column_vector(column,0);
    
    for (int i = 0; i < row;i++)
    {
      for (int j = 0; j < column ; j++)
      {
        if (matrix[i][j] == 0)
        {
          row_vector[i] = -1;
          column_vector[j] = -1;
        }
      }
    }
    
    for (int i = 0; i < row;i++)
    {
      for (int j = 0; j < column ; j++)
      {
        if (row_vector[i] == -1 || column_vector[j] == -1)
        {
          matrix[i][j] = 0;
        }
      }
    }
  }
   /*Time Complexity = O(N*M) traversing two times 
  Space Complexity = O(N+M) Making two vectors*/
  
 
  /*Using the first row and column as the referce vector and handling the edge case differently*/
  void best_solution (vector<vector<int>>& matrix)
  {
    int row = matrix.size();
    int column = matrix[0].size();
    
    bool row_flag = false;
    bool column_flag = false;
    
    for (int i = 0; i < row;i++)
    {
      for (int j = 0; j < column ; j++)
      {
        if (i == 0 && matrix[i][j] == 0)
        {
          row_flag = true;
        }
        if (j== 0 && matrix[i][j] == 0)
        {
          column_flag = true;
        }
        if (matrix[i][j] == 0)
        {
          matrix [0][j] = 0;
          matrix [i][0] = 0;
        }
      }
    }
    
     for (int i = 1; i < row;i++)
    {
      for (int j = 1; j < column ; j++)
      {
        if (matrix[0][j] == 0|| matrix[i][0] == 0)
        {
          matrix [i][j] = 0;
        }
      }
    }
    
    if (row_flag)
    {
      for (int i = 0; i < column;i++)
      {
        matrix[0][i] = 0;
      }
    }
    
    if (column_flag)
    {
      for (int i = 0; i < row;i++)
      {
        matrix[i][0] = 0;
      }
    }  
  }
  /*Time Compleixity = O(N*M)
  Space Complexity = O(1)*/
  
    void setZeroes(vector<vector<int>>& matrix) {
        best_solution(matrix);
    }
};