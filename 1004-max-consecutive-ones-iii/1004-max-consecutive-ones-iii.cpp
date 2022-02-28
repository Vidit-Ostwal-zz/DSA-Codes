class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
      /*Sliding window Approach
      Maximum we can  keep at max k zeros 
      So window restriction will be based on this*/
      
      int st = 0;
      int ed = 0;
      int num_zeros = 0;
      int temp = 0;
      int answer = 0;
      while (ed < nums.size())
      {
        if (nums[ed] == 1)
          temp++;
        
        else
          num_zeros++;
        
        while(num_zeros > k)
          {
            temp -= nums[st];
            if (nums[st] == 0)
              num_zeros--;
            st++;
          }
        
         answer = max(answer,temp+num_zeros);
        ed++;
      }
      return answer;
    }
};