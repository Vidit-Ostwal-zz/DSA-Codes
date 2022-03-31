class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
      
      int ed = 0;
      int st = 0;
      while (ed < k  && ed < nums.size())
      {
        pq.push(make_pair(nums[ed],ed));
        ed++;
      }
      
      vector<int> final_vector;
      final_vector.push_back(pq.top().first);
      // ed++;
      while (ed < nums.size())
      {
        pq.push(make_pair(nums[ed],ed));
        st++;
        
        while (!pq.empty() && pq.top().second < st)
          pq.pop();
        
        final_vector.push_back(pq.top().first);
        ed++;
      }
      return final_vector;
    }
};