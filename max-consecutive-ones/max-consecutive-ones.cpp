class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxones = 0;
      int maxconsecutiveones = 0;
      
      for (int i = 0; i < nums.size(); i++)
      {
        if (nums[i] == 1)
        {
          maxconsecutiveones++;
        }
        else
        {
          maxconsecutiveones = 0;
        }
        maxones = max(maxones,maxconsecutiveones);
      }
      return maxones;
    }
};