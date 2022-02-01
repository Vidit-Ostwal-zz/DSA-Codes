class Solution {
public:
   void swap (int &A, int &B)
  {
    int temp = A;
    A = B;
    B = temp;
  }
  
  
    vector<int> findDuplicates(vector<int>& nums) {
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
          answer.push_back(nums[i]);
      }
      return answer;
    }
};