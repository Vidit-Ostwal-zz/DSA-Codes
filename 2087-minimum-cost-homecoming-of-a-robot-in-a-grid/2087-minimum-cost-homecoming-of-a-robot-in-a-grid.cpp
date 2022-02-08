class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
      int answer = 0;
      
      int sx = startPos[0];
      int ex = homePos[0];
      
      while (sx < ex)
      {
        sx++;
        answer += rowCosts[sx];
      }
      
      while (sx > ex)
      {
        sx--;
        answer += rowCosts[sx];
      }
      
      int sy = startPos[1];
      int ey = homePos[1];
      
      while (sy < ey)
      {
        sy++;
        answer += colCosts[sy];
      }
      
      while (sy > ey)
      {
        sy--;
        answer += colCosts[sy];
      }
      
      return answer;
    }
};