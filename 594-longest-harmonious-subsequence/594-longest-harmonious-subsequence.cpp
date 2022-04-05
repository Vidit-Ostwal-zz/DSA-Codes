class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> u1;
    priority_queue<int> pq;
      
      for (int i = 0; i < nums.size(); i++)
      {
        u1[nums[i]]++;
        if (u1[nums[i]] == 1)
          pq.push(nums[i]);
      }
      
      int temp = pq.top();
      pq.pop();
      
      int answer = 0;
      
      while (!pq.empty())
      {
        int top = pq.top();
        if (temp - top == 1)
          answer = max (answer,u1[temp]+u1[top]);
        temp = top;
        pq.pop();
      }
      return answer;
    }
};