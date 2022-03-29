class Solution {
  int Binary_Search_row(vector<vector<int>> matrix, int target)
  {
    int col = 0;
    int r_st = 0;
    int r_ed = matrix.size()-1;
    
    while (r_st <= r_ed)
    {
      int mid = r_st + (r_ed - r_st)/2;
      
      if (matrix[mid][col] == target)
        return mid;
      
      else if (matrix[mid][col] > target)
        r_ed = mid -1;
      
      else
        r_st = mid + 1;
    }
    return r_ed;
  }
  
  /*Classical Binary Search return index if found, returns -1 if not found*/
/*Two while loops will handle the repeating elements cases*/
int Binary_Search(vector<int> nums, int st, int ed,int target)
 {
  while (st <= ed)
  {
   while (st <= ed && st +1 < nums.size() && nums[st] == nums[st+1])
     st++;
   
    while (st <= ed && ed > 0 && nums[ed] == nums[ed-1])
     ed--;

   int mid = st + (ed - st) / 2;
    
   if (nums[mid] == target)
    return mid;
    
   if (nums[mid] > target)
    ed = mid - 1;
    
   else
    st = mid + 1;
  }
  return -1;
}
  
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int index = Binary_Search_row(matrix,target);
      index = max (0,index);
      return (Binary_Search(matrix[index],0,matrix[index].size()-1,target) != -1);
    }
};