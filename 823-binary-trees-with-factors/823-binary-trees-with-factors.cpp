class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
      
      unordered_map<int,int> prev_values;
      vector<long long> dp(arr.size(),1);
      sort (arr.begin(),arr.end());
      long long answer  = 0;
      
      for (int i = 0; i < arr.size(); i++)
      {
        int curr_number = arr[i];
        long long temp_answer = 1;
        
        for (int i = 1; i <= pow(curr_number,0.5); i++)
        {
          if (curr_number % i == 0 && prev_values[i] && prev_values[curr_number/i])
          {
            int flag = 2;
            if (curr_number/i == i)
              flag = 1;
            temp_answer += flag * dp[prev_values[i]-1] * dp[prev_values[curr_number/i]-1];
          }
        }
        dp[i] = temp_answer;
        prev_values[arr[i]] = i+1;
        answer += temp_answer;
        // cout << temp_answer << endl;
      }
      return answer % (int)(pow(10,9) + 7);
    }
};