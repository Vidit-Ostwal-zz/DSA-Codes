class Solution {
  /*Classical Binary Search return index if found, returns -1 if not found*/
int Binary_Search(vector<int> nums, int st, int ed)
 {
  int answer = -1;
  while (st <= ed)
  {
   int mid = st + (ed - st) / 2;
    
   if (nums[mid] < 0)
   {
     answer = mid;
     ed = mid - 1;
   }
    
   else if  (nums[mid] >= 0)
    st = mid + 1;
  }
  return answer;
}
public:
    int countNegatives(vector<vector<int>>& grid) {
      int answer = 0;
      for (int i = 0; i < grid.size(); i++)
      {
        int temp = Binary_Search(grid[i],0,grid[i].size()-1);
        cout << temp << endl;
        if (temp != -1)
          answer += grid[i].size() - temp;
      }
      return answer;
    }
};