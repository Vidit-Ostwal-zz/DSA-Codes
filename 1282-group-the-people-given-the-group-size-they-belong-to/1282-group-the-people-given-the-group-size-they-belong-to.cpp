class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> mp;
      
      for (int i =0; i < groupSizes.size(); i++)
        mp[groupSizes[i]].push_back(i);
      
      vector<vector<int>> answer;
      
      auto it = mp.begin();
      for (; it != mp.end();it++)
      {
        int size = it -> first;
        vector<int> temp = it -> second;
        vector<int> temp1;
        for (int i = 0; i < temp.size();)
        {
          vector<int>temp1(temp.begin()+i,temp.begin()+i+size);
          answer.push_back(temp1);
          i += size;
        }
      }
      return answer;
    }
};