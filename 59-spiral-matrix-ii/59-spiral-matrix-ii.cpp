class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int value = 1;
      vector<vector<int>> final_vector (n,vector<int>(n,0));
      
      int start_row = 0;
      int end_row = n-1;
      int start_col = 0; 
      int end_col = n-1;
      
      
      while (value <= n*n)
      {
        int i = start_col;
        while (value <= n*n && i <= end_col)
        {
          final_vector[start_row][i] = value;
          value++;
          i++;
        }
        
        int j = start_row+1;
        while (value <= n*n && j <= end_row)
        {
          final_vector[j][end_col] = value;
          value++;
          j++;
        }
        
        int k = end_col-1;
        while (value <= n*n && start_row != end_row && k >= start_col)
        {
          final_vector[end_row][k] = value;
          value++;
          k--;
        }
        
        int l = end_row-1;
        while (value <= n*n && start_col != end_col && l >= start_row+1)
        {
          final_vector[l][start_col] = value;
          value++;
          l--;          
        }
        
        start_row++;
        end_row--;
        start_col++;
        end_col--;
      }
      return final_vector;
    }
};