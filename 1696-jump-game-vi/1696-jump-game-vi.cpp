class Solution {
  map<int,int,greater<int>> scoremap;
  void map_remove(int key)
  {
    scoremap[key]--;
    
    if (!scoremap[key])
      scoremap.erase(key);
    
    return ;
  }
  
  void show_vector(vector<int> vect)
{
  for (auto&it:vect)
  {
    cout << it << "   ";
    // cout << it.first << "  " << it.second << endl;
  }
    cout << endl;
}

public:
    int maxResult(vector<int>& nums, int k) {
      
      vector<int> dp(nums.size(),0);
     
      
      dp[0] = nums[0];
      scoremap[dp[0]]++;
      
      for (int i = 1; i <= k && i < nums.size() ; i++)
      {
        int max_score = scoremap.begin() -> first;
        
        dp[i] = nums[i] + max_score;
        scoremap[dp[i]]++;
      }
      
      map_remove(dp[0]);
      
      int i = k+1;
      int j = 1;
      
      
      while (i < dp.size())
      {
        int max_score = scoremap.begin() -> first;
        
        dp[i] = nums[i] + max_score;
        scoremap[dp[i]]++;
        
        map_remove(dp[j++]);
        i++;
      }
      // show_vector(dp);
      return dp[nums.size()-1];
    }
};