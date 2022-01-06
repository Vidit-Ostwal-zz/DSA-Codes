class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      /*  Handling the case when nums is empty  */  
      
      if (nums.size() == 0)
      {
        return 0;
      }
      
      int start = 0;
      int next = 0;
      
      
      while (next < nums.size())
      {
         while (next+1 < nums.size() && nums[next] == nums[next+1])
         {
           next++;
         }
        if (nums[start]!= nums[next])
        {
          nums[start] = nums[next];
        }
        start++;
        next++;
      }
      return start;
    }
};