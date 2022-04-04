class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> sum (mat.size(),vector<int>(mat[0].size(),0));
       vector<vector<int>> answer (mat.size(),vector<int>(mat[0].size(),0));
      for (int i = 0; i < mat.size(); i++)
      {
        for (int j = 0; j < mat[0].size(); j++)
        {
          if (j == 0)
            sum[i][j] = mat[i][j];
          else
            sum[i][j] = sum[i][j-1] + mat[i][j];
        }
      }
     
      int size = mat.size();
      int size_y = mat[0].size();
      for (int i = 0; i < answer.size(); i++)
      {
        for (int j = 0; j < answer[0].size(); j++)
        {
          int x_min = max(0,i-k);
          int x_max = min((i+k),(size-1));
          int y_min = max(-1,j-k-1);
          int y_max = min(j+k,size_y-1);
          
          int sum1 = 0;
          
          for (int i = x_min; i <= x_max; i++)
          {
            sum1 += sum[i][y_max];
            sum1 -= (y_min >= 0) ? sum[i][y_min] : 0;
          }
          
          answer[i][j] = sum1;
        }
      }
      return answer;
    }
};