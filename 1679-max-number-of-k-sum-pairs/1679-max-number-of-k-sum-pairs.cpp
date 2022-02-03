class Solution {
public:
    int maxOperations(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() -1;
        sort(nums.begin(),nums.end());
      int answer = 0;
        while (start < end)
        {
          int sum  = nums[start] + nums[end];
          
          if (sum  == target)
          {
            answer++;
            start++;
            end--;
          }
          else if (sum > target)
            end--;
          
          else
            start++;
          
        }
      return answer;
    }
};