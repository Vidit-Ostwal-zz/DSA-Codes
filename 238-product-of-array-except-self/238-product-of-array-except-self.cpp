class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
      
      int zero_count = 0;
      for (int i = 0; i < nums.size(); i++)
      {
        if (nums[i])
          product *= nums[i];
        else
          zero_count++;
      }
      
       vector<int> answer(nums.size(),0);
      if (zero_count > 1)
        return answer;
      
      if (zero_count == 1)
      {
        for (int i = 0; i < nums.size(); i++)
        {
          if (nums[i] == 0)
          {
            answer[i] = product;
            break;
          }
        }
        return answer;
      }
      
      for (int i = 0; i < nums.size(); i++)
      {
        answer[i] = product/nums[i];
      }
      
      return answer;
    }
};