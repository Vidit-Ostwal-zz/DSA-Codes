class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int st = prices[0];
      int answer = 0;
      
      for (int i = 1; i < prices.size(); i++)
      {
        answer = max(answer,prices[i]-st);
        st = min(st,prices[i]);
      }
      return answer;
    }
};