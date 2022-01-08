class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start_index = 0;
      int end_index = 0;
      int sum = 0;
      int answer = INT_MAX;
      while (end_index < nums.size())
      {
        if (sum < target)
        {
          sum += nums[end_index];
          end_index++;
        }
        else
        {
          sum -= nums[start_index];
          start_index++;
        }
        
        if (sum >= target)
        {
          answer = (answer > end_index - start_index ?  end_index - start_index :answer) ;
        }
      }
      while (sum >= target)
      {
        sum -= nums[start_index];
        start_index++;
        if (sum >= target)
        {
          answer = (answer > end_index - start_index ?  end_index - start_index :answer) ;
        }
      }
      if (start_index == 0 && end_index == nums.size())
      {
        return 0;
      }
      return answer;
    }
};