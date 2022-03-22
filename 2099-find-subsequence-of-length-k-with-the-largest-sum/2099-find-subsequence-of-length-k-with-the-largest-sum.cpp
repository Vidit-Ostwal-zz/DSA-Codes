class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
      for (int i = 0; i < nums.size();i++)
        pq.push({nums[i],i});
      
      vector<int> vec1;
      while (k)
      {
        vec1.push_back(pq.top().second);
        pq.pop();
        k--;
      }
      
      sort(vec1.begin(),vec1.end());
      
      vector<int> answer;
      for (int i = 0; i < vec1.size(); i++)
        answer.push_back(nums[vec1[i]]);
      
      return answer;
    }
};