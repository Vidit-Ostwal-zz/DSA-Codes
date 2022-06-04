class NumMatrix {
  vector<vector<int>> B;
public:
    NumMatrix(vector<vector<int>>& A) {
      B = vector<vector<int>>(A.begin(),A.end());
      
      for (int j = 0; j < B[0].size(); j++)
          for (int i = 0; i < B.size(); i++)
            if (i)
              B[i][j] += B[i-1][j];
      
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // Range Quesries Prefix Sum Always Helps
      int sum = 0;
      for (int i = col1; i <= col2; i++)
      {
        sum += B[row2][i];
        sum -= (row1) ? B[row1-1][i] : 0;
      }
      return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */