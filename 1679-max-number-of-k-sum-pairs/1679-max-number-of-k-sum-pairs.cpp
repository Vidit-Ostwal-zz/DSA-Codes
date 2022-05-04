class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> u1;
      int answer = 0;
      
      for (int i = 0; i < nums.size(); i++)
      {
        if (u1.find(k - nums[i]) == u1.end())
          u1[nums[i]]++;
        else 
        {
          answer++;
          
          u1[k-nums[i]]--;
          if (u1[k-nums[i]] == 0)
            u1.erase(k-nums[i]);
        }
      }
      return answer;
    }
};