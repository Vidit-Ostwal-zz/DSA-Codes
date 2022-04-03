class Solution {
  vector<int> answer;
  int max_used = 0;
  int maxi = 0;
  void getme(int arrows, vector<int> alice, vector<int> temp, int index, int sum)
  {
    if (index == alice.size() || arrows == 0)
    {
      if (sum >  maxi)
      {
        maxi = sum;
        max_used = arrows;
        answer = vector<int>(temp.begin(),temp.end());
      }
      return ;
    }
    
    getme(arrows,alice,temp,index+1,sum);
    if (arrows >= alice[index]+1)
    {
      temp[index] = (alice[index]+1);
      getme(arrows - alice[index] - 1,alice, temp,index+1, sum + index);
    }
    
  }
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
     vector<int>temp(aliceArrows.size(),0);
        getme(numArrows,aliceArrows,temp,1,0);
      
      answer[0] = max_used;
      return answer;
    }
};