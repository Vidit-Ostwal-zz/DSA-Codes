class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() -1;
        
        while (start < end)
        {
          int sum  = nums[start] + nums[end];
          
          if (sum  == target)
          {
            vector<int> answer;
            answer.push_back(start+1);
            answer.push_back(end+1);
            return answer;
          }
          else if (sum > target)
            end--;
          
          else
            start++;
        }
      return {};
    }
};