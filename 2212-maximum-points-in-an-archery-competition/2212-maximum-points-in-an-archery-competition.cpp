class Solution {
  unordered_map<int,vector<vector<int>>> map;
  int recursion_memo(vector<int> Bob, vector<int> Alice, int index, int num,int temp_sum)
  {  
    if (num == 0)
    {
      map[temp_sum].push_back(Bob);
      return temp_sum;
    }
    
    if (index == Alice.size())
    {
      map[temp_sum].push_back(Bob);  
      return temp_sum;
    }
    if (Alice[index] +1 > num)
      return recursion_memo(Bob,Alice,index+1,num,temp_sum);
    
    int option1 = recursion_memo(Bob,Alice,index+1,num,temp_sum);
    Bob[index] = Alice[index] +1;
    temp_sum += index;
    int option2 = recursion_memo(Bob,Alice,index+1,num-Bob[index],temp_sum);
    
    return max(option1,option2);
  }
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> BobArrows(aliceArrows.size(),0);
      
      vector<vector<int>> dp(aliceArrows.size()+1,vector<int>(numArrows + 1,-1));
      int index = recursion_memo (BobArrows,aliceArrows,0,numArrows,0);
      
      vector<int> vec1 = map[index][0];
      
      int arrow_used = 0;
      for (int i = 0; i < vec1.size(); i++)
        arrow_used += vec1[i];
      
      vec1[0] = numArrows - arrow_used;
      return vec1;
    }
};