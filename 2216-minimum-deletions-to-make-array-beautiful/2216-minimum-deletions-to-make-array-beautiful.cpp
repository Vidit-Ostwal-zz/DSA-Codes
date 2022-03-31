class Solution {
public:
    int minDeletion(vector<int>& nums) {
      
      int st = 0;
      int ed = 1;
      int count = 0;
      int count11 = 0;
      while (ed <  nums.size())
      {
        if (nums[st] != nums[ed])
        {
          count11++;
          st = ed+1;
          ed = ed+2;
        }
        else
        {
          ed++;
          count++;
        }
      }
      return nums.size() - 2*count11;
    }
};