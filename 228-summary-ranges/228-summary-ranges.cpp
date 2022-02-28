class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> answer;
      
      int st = 0;
      int ed = 0;
      
      while (ed < nums.size())
      {
        if (ed+1 < nums.size() && nums[ed+1] == nums[ed] + 1)
          ed++;
        else
        {
          if (ed == st)
            answer.push_back(to_string(nums[ed]));
          else
            answer.push_back(to_string(nums[st]) + "->" + to_string(nums[ed]));
          
          ed++;
          st=ed;
        }
      }
      return answer;
    }
};