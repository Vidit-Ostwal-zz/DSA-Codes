class Solution {
public:
    int minPairSum(vector<int>& nums) {
      sort(nums.begin(),nums.end());
        int answer = 0;
      int start = 0;
      int end = nums.size()-1;
      
      while (start < end)
      {
        answer = max(nums[start]+nums[end],answer);
        start++;
        end--;
      }
      
      return answer;
    }
};