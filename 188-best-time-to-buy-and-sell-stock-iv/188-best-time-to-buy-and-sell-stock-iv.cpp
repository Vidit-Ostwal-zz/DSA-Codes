class Solution {
  vector<vector<int>> u1_true;
  vector<vector<int>> u1_false;
  int K=  0;
  int max_profit (vector<int> p, int i,bool flag, int count)
  {
    if (i == p.size() || count == K)
      return 0;
    
    if (flag)
    {
      if (u1_true[i][count] != INT_MIN)
        return u1_true[i][count];
       return u1_true[i][count] = max (max_profit(p,i+1,!flag,count)-p[i],max_profit(p,i+1,flag,count));
    }
     
    if (u1_false[i][count] != INT_MIN)
         return u1_false[i][count];
    return u1_false[i][count] = max(max_profit(p,i+1,!flag,count+1)+p[i],max_profit(p,i+1,flag,count));
  }
public:
    int maxProfit(int k, vector<int>& temp) {
      if (temp.size() == 0)
        return 0;
      
      K = k;
         int i = temp.size() -1;
      while (i >= 0 && temp[i] == 0)
        i--;
      
      vector<int> prices(temp.begin(),temp.begin() +i +1);
      u1_true = vector<vector<int>> (prices.size(),vector<int>(k,INT_MIN));
        u1_false = vector<vector<int>> (prices.size(),vector<int>(k,INT_MIN));
        return max_profit (prices, 0,true,0);
    }
};