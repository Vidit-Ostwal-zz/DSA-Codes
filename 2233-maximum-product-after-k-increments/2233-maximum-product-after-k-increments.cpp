class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
      
      for (int i=  0; i < nums.size(); i++)
        pq.push(nums[i]);
      
      while (k)
      {
        int temp = pq.top();
        pq.pop();
        temp++;
        pq.push(temp);
        k--;
      }
      long long answer = 1;
      
      while (!pq.empty())
      {
        // cout << pq.top() << "  " << endl;
        answer *= pq.top();
        answer = answer%1000000007;
        // cout << answer << endl;
        pq.pop();
      }
      return answer;
    }
};