class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0;
      int right = 0;
      int max = INT_MIN;
      while (left < nums.size() && !nums[left])
      {
        left++;
        right++;
      }
      if (right == nums.size())
      {
        return 0;
      }
      /*They both would be at first position where 1 is there*/
      {
        while (right < nums.size())
        {
          while (right + 1 < nums.size() && nums[right + 1] == 1)
          {
            right++;
          }
          cout << max << endl;
          if (max < right-left+1)
          {
            max = right - left + 1;
          }
          while (right + 1 < nums.size() && !nums[right + 1])
          {
            right++;
          }
          right ++;
          left = right;
        }
      }
      return max;
    }
};