class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
      unordered_map<int,int> map;
      
      for (int i = 0; i < nums.size()-1 ;i++)
      {
        if (nums[i] == key)
          map[nums[i+1]]++;
      }
      
      int mini = INT_MIN;
      int answer=  -1;
      
      auto it = map.begin();

      while (it != map.end())
      {
        if (mini < it -> second)
        {
          answer = it -> first;
          mini = it -> second;
        }
        it++;
      }
      return answer;
    }
};