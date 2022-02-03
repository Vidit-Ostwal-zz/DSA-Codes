class Solution {
public:
  /*Combining Linear Search to fix the first element and then performing 
  using a two pointer approach to get other two indexes
  Sorting is important*/
    vector<vector<int>> threeSum(vector<int>& nums) {
      
      if (nums.size() < 3)
        return {};
      
      sort(nums.begin(),nums.end());
      int target = 0;
      
      set<vector<int>> set1;
      for (int i = 0; i < nums.size()-2; i++)
      {
        int first = nums[i];
        
        int start = i+1;
        int end = nums.size()-1;
        
        while (start < end)
        {
          int sum = first + nums[start] + nums[end];
          if ( sum == target)
          {
            vector<int> temp = {first,nums[start],nums[end]};
            set1.insert(temp);
            start++;
            end--;
          }
          else if (sum > target)
          {
            end--;
          }
          else
          {
            start++;
          }
        }
      }
      vector<vector<int>> answer(set1.begin(),set1.end());
      return answer;
    }
};