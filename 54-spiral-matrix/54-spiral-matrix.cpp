class Solution {
  vector<int> spiral (vector<vector<int>> matrix, int start_row, int end_row, int start_col, int end_col)
  {
    
    
    if (start_row > end_row || start_col > end_col)
      return {};
 
    vector<int> final_vector;
    int i = start_col;
    while (i <= end_col)
    {
      final_vector.push_back(matrix[start_row][i]);
      i++;
    }
    int j = start_row+1;
    while (j <= end_row)
    {
      final_vector.push_back(matrix[j][end_col]);
      j++;
    }
    int k = end_col-1;
    while(start_row != end_row && k >= start_col)
    {
      final_vector.push_back(matrix[end_row][k]);
      k--;
    }
    int l = end_row -1;
    while (start_col != end_col && l >= start_row+1)
    {
      final_vector.push_back(matrix[l][start_col]);
      l--;
    }
    
    vector<int> temp_vector = spiral(matrix,start_row+1, end_row -1, start_col +1, end_col -1);
    final_vector.insert(final_vector.end(),temp_vector.begin(),temp_vector.end());
    return final_vector;
  }
  
  
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        return spiral (matrix, 0,matrix.size()-1, 0, matrix[0].size()-1);
    }
};