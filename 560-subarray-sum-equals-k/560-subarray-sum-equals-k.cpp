class Solution {
  /*Using Cummulative Sum */
  /*Consider Every Sub Array Sum */
  /**/
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
      
      int sum = 0;
      int answer = 0;
      for (int i = 0; i < nums.size(); i++)
      {
          sum += nums[i];
        
        if (sum == k)
          answer++;
        
        
        if (mp.find(sum-k) != mp.end())
          answer += mp[sum-k];
        
      
        
        mp[sum]++;
      }
      return answer;
    }
};