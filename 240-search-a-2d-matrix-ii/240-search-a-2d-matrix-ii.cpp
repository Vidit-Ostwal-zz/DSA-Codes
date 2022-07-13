class Solution {
public:
    bool searchMatrix(vector<vector<int>>& A, int target) {
        
      // Taking rightMost, uppermost element as starting point
      // It's left side is smaller than this element 
      // It's bottom side is larget than this element
      
      int x = 0;
      int y = A[0].size()-1;
      
      while (x >= 0 && x < A.size() && y >= 0 && y < A[0].size())
      {
        if (A[x][y] == target)
          return true;
        
        if (A[x][y] > target)
          y--;
        else
          x++;
      }
      return false;
    }
};