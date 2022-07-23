class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int n = rolls.size();
      
      int ans = 1;
      int c = 0;
      unordered_map<int,int> map1;
      
      for (int i = 0; i < rolls.size(); i++)
      {
        map1[rolls[i]]++;
        
        if (map1.size() == k)
        {
          map1.clear();
          ans++;
        }
      }
      return ans;
    }
};