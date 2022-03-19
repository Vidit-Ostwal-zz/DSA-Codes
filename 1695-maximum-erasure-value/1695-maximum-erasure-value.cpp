class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> map;
      int ed = 0;
      int st = 0;
      
      int answer = 0;
      int temp_sum = 0;
      
      while (ed < nums.size())
      {
        temp_sum += nums[ed];
        map[nums[ed]]++;
        
        while (map[nums[ed]] != 1)
        {
          temp_sum -= nums[st];
          map[nums[st]]--;
          if (map[nums[st]] == 0)
            map.erase(map[nums[st]]);
          
          st++;
        }
        answer = max(answer, temp_sum);
        ed++;
      }
      return answer;
    }
};