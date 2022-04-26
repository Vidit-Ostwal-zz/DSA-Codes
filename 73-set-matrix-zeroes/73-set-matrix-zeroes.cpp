class Solution {
  /*Approach 1 = Take a queue which contains all the indexes of the matrix where zeros occur, and then one by one for all the element change the matrix
  TC = O(N*M)*O(N+M)
  SC = O(N*M)
  
  Approach 2 = Make Two vector row column, iterate over the whole matrix and find which row and xolumn should be change and then iterate over each row and column vector to change the matrix
  TC = O(N*M) + O(N)*O(M) + O(M)*O(N)
  SC = O(N) + O(M)
  
  Approach 3 =  No Space complexity,  which means we need to use some kind of way to use the rows and column in the matrix as our row and column vector, now we can use our own 1st row and 1st column to do this, and we can change the first row and first column according to the, and the  again iterate to get the final solutionor we can again iterate and check whether the particular row index or xolumn index element is zero or not
  We need to handle the edge case in the first row and first column very carefully fr which we can use extra variable
  TC = O(N*M) + O(N)*O(M) + O(M)*O(N)*
  SC = O(1)*/
  
  void approach3 (vector<vector<int>>& matrix)
  {
    bool row = false;
    bool col = false;
    
    for (int j = 0; j < matrix[0].size(); j++)
      if (matrix[0][j] == 0)
      {
        row = true;
        break;
      }
    
    for (int i = 0; i < matrix.size(); i++)
      if (matrix[i][0] == 0)
      {
        col = true;
        break;
      }
    
    for (int i =  1; i < matrix.size(); i++)
      for (int j = 1; j < matrix[0].size(); j++)
        if (matrix[i][j] == 0)
        {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
    
    for (int i =  1; i < matrix.size(); i++)
      for (int j = 1; j < matrix[0].size(); j++)
        if (matrix[0][j] == 0 || matrix[i][0] == 0)
          matrix[i][j] = 0;
    
    if (col)
    {
      for (int i = 0; i < matrix.size(); i++)
        matrix[i][0] = 0;
    }
    
    if (row)
    {
      for (int j = 0; j < matrix[0].size(); j++)
        matrix[0][j] = 0;
    }
  }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        approach3 (matrix);
    }
};