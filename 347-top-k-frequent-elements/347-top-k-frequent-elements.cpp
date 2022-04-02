class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
      
      for (int i = 0; i < nums.size(); i++)
        map[nums[i]]++;
      
      priority_queue<pair<int,int>> pq;
      
      auto it = map.begin();
      
      while (it != map.end())
      {
        pq.push({it->second,it-> first});
        it++;
      }
      
      vector<int> final_vector;
      
      while (k && !pq.empty())
      {
        final_vector.push_back(pq.top().second);
        k--;
        pq.pop();
      }
      return final_vector;
    }
};