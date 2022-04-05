class Solution {
  long long get_count (vector<int> prices, int index, int prev)
  {
    if (index == prices.size())
      return ((index-prev)*(index-prev+1))/2;
    
    if (index == 0)
      return  get_count(prices, index+1, prev);
    
    if (prices[index-1] - prices[index] == 1)
      return get_count(prices,index+1,prev);
    
    return ((index-prev)*(index-prev+1))/2 + get_count(prices,index+1,index);
  }
public:
    long long getDescentPeriods(vector<int>& prices) {
        // return get_count(prices,0,0);
      
      vector<long long> dp(prices.size(),0);
      dp[0] = 1;
      long long  prev = 0;
      for (int i = 1; i < prices.size(); i++)
      {
        if (prices[i-1] - prices[i] == 1)
        {}
        else
          prev = i;
        
        dp[i] = ((i-prev+1)*(i-prev+2))/2 + ((prev-1 >= 0) ? dp[prev-1] : 0);
      }
      return dp[prices.size()-1];
    }
};