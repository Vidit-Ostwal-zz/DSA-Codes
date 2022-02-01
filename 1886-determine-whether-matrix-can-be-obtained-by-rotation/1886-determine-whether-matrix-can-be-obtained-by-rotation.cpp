class Solution {
  void rotate(vector<vector<int>>& A) {
        int row_st_index = 0;
    int row_end_index = A.size()-1;
    int col_st_index = 0;
    int col_end_index = A[0].size()-1;

    while (row_st_index < row_end_index)
    {
        int number = col_end_index - col_st_index;
        for (int i = 0; i < number; i++)
        {
             int temp = A[row_st_index][col_st_index+i];
             A[row_st_index][col_st_index+i] = A[row_end_index-i][col_st_index];
             
            
             int second = A[row_st_index+i][col_end_index]; 
             A[row_st_index+i][col_end_index] = temp;

            
             temp = second;

             second = A[row_end_index][col_end_index-i];
              A[row_end_index][col_end_index-i] = temp;
            

            temp = second;
            A[row_end_index-i][col_st_index] = temp;
        }
        row_st_index++;
        row_end_index--;
        col_st_index++;
        col_end_index--;
    }
}
  
  bool check(vector<vector<int>> mat, vector<vector<int>> target)
  {
    for (int i  =0; i < mat.size(); i++)
    {
      for (int j = 0; j< mat[0].size();j++)
      {
        if (mat[i][j] != target[i][j])
          return false;
      }
    }
    return true;
  }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
      bool flag = check(mat,target);
      if (flag) return flag;
      
      for (int i = 0; i < 3;i++)
      {
        rotate(mat);
        if (check(mat,target))
          return true;
      }
      return false;
    }
};