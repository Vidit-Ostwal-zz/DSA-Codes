class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
      
      int sum = 0;
      int count = 0;
      for (int i = 0; i < nums.size(); i++)
      {
        sum += nums[i];
    
        if (sum % k == 0)
          count++;
        
        if (mp.find( ((sum % k) +k) % k ) != mp.end())
          count += mp[((sum % k) +k) % k];
        
        mp[((sum % k) +k) % k]++;
      }
      return count;
    }
};