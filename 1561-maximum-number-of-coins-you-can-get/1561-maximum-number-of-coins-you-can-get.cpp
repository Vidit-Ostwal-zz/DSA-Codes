class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
      
      int st = 0;
      int ed = piles.size() - 2;
      
      int ans = 0;
      while (st <= ed)
      {
        ans += piles[ed];
        ed--;
        ed--;
        st++;
      }
      return ans;
    }
};