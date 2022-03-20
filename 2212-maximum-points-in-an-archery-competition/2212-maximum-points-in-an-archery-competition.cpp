class Solution {
  vector<int> answer;
  int maxi = INT_MIN;
  int left;
  void recur(int numArrows, vector<int> alice, int profit,int index, vector<int> Bob)
  {
    if (numArrows == 0 || index >= alice.size())
    {
      if (maxi < profit)
      {
        left = numArrows;
        maxi = profit;
        answer = Bob;
      }
      return ;
    }
    
    recur(numArrows,alice,profit,index+1,Bob);
    
    int req_arrow = alice[index] + 1 ;
    
    if (req_arrow <= numArrows)
    {
      Bob[index] = req_arrow;
      numArrows -= req_arrow; 
      recur(numArrows,alice,profit+index,index+1,Bob);
    }
  }
  
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
      vector<int>Bob(aliceArrows.size(),0);
      
        recur(numArrows,aliceArrows,0,0,Bob);
      answer[0] += left;
      
      for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << "   " ;
      
      cout << endl;
      return answer;
    }
};