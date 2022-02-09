class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
      unordered_map<int,int> mp;
    sort(nums.begin(),nums.end());
      for (int i  =0 ;i < nums.size(); i++)
        mp[nums[i]]++;
      
      int answer = 0;
      
      if (k > 0)
      {
        for (int i = 0; i < nums.size() ;i++)
        {
          if (mp.find(nums[i]) != mp.end())
          {
            mp.erase(nums[i]);
            
            if (mp.find(nums[i]+k) != mp.end())
            {
              cout<<"  hfhj"<<endl;
               answer++;
            }
          }
          cout << answer << "   "  << nums[i] << endl;
        }
      }
      else
      {
        for (int i = 0; i < nums.size(); i++)
        {
          if (mp.find(nums[i]) != mp.end())
          {
            if (mp[nums[i]] > 1)
              answer++;
            
            mp.erase(nums[i]);
          }
        }
      }
      return answer;
      
    }
};