class Solution {
  vector<vector<int>> u1_true;
  vector<vector<int>> u1_false;
  
  int canwin(vector<int> piles, int st, int ed,int alice, int bob ,bool flag)
  { 
    if (st == ed)
    {
      if (flag)
        alice += piles[st];
      else
        bob += piles[st];
      return (alice > bob) ? 1 : 0;
    }
    
    if (flag)
    {
      if (u1_true[st][ed] != -1)
        return u1_true[st][ed];
      
      return  u1_true[st][ed] = canwin(piles,st+1,ed,alice+piles[st],bob,!flag) || canwin(piles,st,ed-1,alice+piles[ed],bob,!flag);
    }
     if (u1_false[st][ed] != -1)
        return u1_false[st][ed];
    return u1_false[st][ed] = canwin(piles,st+1,ed,alice,bob+piles[st],!flag) || canwin(piles,st,ed-1,alice,bob+piles[ed],!flag);
    
    
  }
public:
    bool stoneGame(vector<int>& piles) {
     u1_true = vector<vector<int>>(piles.size(),vector<int>(piles.size(),-1));
      u1_false = vector<vector<int>>(piles.size(),vector<int>(piles.size(),-1));
      
        return canwin(piles,0,piles.size()-1,0,0,true);
    }
};