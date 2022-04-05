class Solution {
  int min_time (string colors, vector<int> time, int index, string temp)
  {
    if (index == colors.length())
      return 0;
    
    if (temp.length() == 0)
      return min(min_time(colors,time,index+1,temp+colors[index]) ,min_time(colors,time,index+1,temp) + time[index] );
    else if (colors[index] == temp[temp.length()-1])
      return min_time(colors,time,index+1,temp) + time[index];
    return min(min_time(colors,time,index+1,temp+colors[index]),min_time(colors,time,index+1,temp) + time[index]);
  }
public:
    int minCost(string colors, vector<int>& neededTime) {
        // return min_time (colors, neededTime, 0, "");
      vector<int> freq(26,-1);
      vector<int> dp (colors.length(),0);
      dp[0] = neededTime[0];
      int sum = dp[0];
      freq[colors[0] -'a'] = 0;
      for (int i=  1; i < colors.length(); i++)
      {
        freq[colors[i] -'a'] = i;
        sum += neededTime[i];
        int option1 = dp[i-1];
        int j = INT_MIN;
        
        for (int k = 0; k < 26; k++)
          if (k != (colors[i]-'a'))
            j = max(j,freq[k]);
        
        int option2 = neededTime[i] + ((j >= 0) ? dp[j] : 0);
        
        dp[i] = max (option1, option2);
      }
      
      return sum - dp[neededTime.size()-1];
    }
};