class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
      /*Kadane's Algorithms
      Maximum Subarray Sum*/
      
      int answer = INT_MIN;
      int temp = 0;
      int i = 0;
      while (i < nums.size())
      {
        if (nums[i] == 0)
        {
          answer = max(answer,temp);
          temp = 0;
        }
        else
          temp++;
        
        i++;
      }
      answer = max(answer,temp);
      return answer;
    }
};