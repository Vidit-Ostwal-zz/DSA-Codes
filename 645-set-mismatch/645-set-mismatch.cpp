class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int i = 0;
      
      while (i < nums.size())
      {
        int correct_index = nums[i] - 1;
        if (nums[i] != nums[correct_index])
        {
          swap(nums[i],nums[correct_index]);
        }
        else
        {
          i++;
        }
      }
   
   vector<int> answer;
      for (int i = 0; i < nums.size(); i++)
      {
        if (nums[i] != i+1)
        {
          answer.push_back(nums[i]);
           answer.push_back(i+1);
        }
      }
      return answer;
    }
};