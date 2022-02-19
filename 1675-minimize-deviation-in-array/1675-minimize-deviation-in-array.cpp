class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
      int maxi = INT_MIN;
      int mini = INT_MAX;
      
      for (int i = 0; i < nums.size(); i++)
      {
        if (nums[i] % 2 != 0)
          nums[i] = nums[i]*2;
        
        maxi = max(maxi,nums[i]);
        mini = min(mini,nums[i]);
      }
      
      int min_deviation = maxi - mini;
      
      priority_queue<int> pq;
      for (int i = 0; i < nums.size(); i++)
        pq.push(nums[i]);
      
      while(pq.top() % 2 == 0)
      {
        int top = pq.top();
        pq.pop();
        min_deviation = min(min_deviation,top-mini);
        top = top / 2;
        mini = min(mini,top);
        pq.push(top);
      }
      min_deviation = min(min_deviation,pq.top() - mini);
      
      return min_deviation;
    }
};