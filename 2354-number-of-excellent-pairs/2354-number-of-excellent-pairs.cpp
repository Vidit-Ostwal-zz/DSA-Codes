class Solution {
  int setbitcount(int num1)
  {
    int count = 0;
    
    while (num1)
    {
      if (num1 & 1)
        count++;
      num1 = num1 >> 1;
    }
    return count;
  }
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        long long answer = 0;
      
      map<int,int> map1;
      set<int> set1;
      
      for (int i = 0; i < nums.size(); i++)
      {
        if (!set1.count(nums[i]))
        {
          map1[setbitcount(nums[i])]++;
          set1.insert(nums[i]);
        }
      }
      
      auto it = map1.begin();
      
      
      while (it != map1.end())
      {
        // cout << k << endl;
        // cout << it -> first << endl;
        // cout << k - (it -> first) << endl;
        auto search = map1.lower_bound(k - it->first);
        while (search != map1.end())
        {
          answer += (it -> second)*(search -> second);
          search++;
        }
        it++;
      }
        return answer;
    }
};