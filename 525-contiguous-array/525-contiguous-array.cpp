class Solution {
public:
    int findMaxLength(vector<int>& nums) {
         for (int i = 0; i < nums.size();i++)
           nums[i] = (nums[i] == 0)  ? -1 : 1;
      
      int max_length = 0;
      int end_index = 0;
      int sum = 0;
      unordered_map<int,int> mp;
      
      for (int i = 0 ; i < nums.size();i++)
      {
        sum += nums[i];
        
        /*Sum is zero from starting from zero*/
        if (sum == 0)
        {
          max_length = i+1;
          end_index = i;
        }
        
        if (mp.find(sum) != mp.end())
        {
          if (max_length < i - mp[sum])
          { 
            max_length = i - mp[sum];
            end_index = i;
          }
        }
        else
          mp[sum] = i;
      }
      return max_length;
    }
};