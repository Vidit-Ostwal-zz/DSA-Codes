class Solution {
  int Helper (vector<int> nums,int diff)
  {
    unordered_map<int,int> map1;
    int answer = 1;
    for (int i = 0; i < nums.size(); i++)
    {
      int temp_diff = nums[i] - diff;
      
      if (map1.find(temp_diff) != map1.end())
        map1[nums[i]] = max(map1[nums[i]],1+map1[temp_diff]);
      else
        map1[nums[i]] = max(map1[nums[i]],1);
      
      answer = max(answer,map1[nums[i]]);
    }
    return answer;
  }
public:
    int longestArithSeqLength(vector<int>& A) {
      
//       int mini = INT_MAX;
//       int maxi = INT_MIN;
      
//       for (auto &x: nums)
//       {
//         mini = min(mini,x);
//         maxi = max(maxi,x);
//       }
      
//       int diff = maxi - mini;
      
//       int low_diff = -1*diff;
      
      
//       int max_length = -1;
      
//       for (int i = 0; i <= diff; i++)
//       {        
//         max_length = max(max_length,Helper(nums,i));
//         max_length = max(max_length,Helper(nums,-1*i));
        
//         if (max_length == nums.size())
//         {
//           return nums.size();
//         }
        
        
//       }
      
//       return max_length;
      int max_element = 0;
    int min_element = INT_MAX; 
    
    for (auto &x: A)
    {
        max_element = max(max_element,x);
        min_element = min(min_element,x);
    }
    long long m = max_element - min_element + 1; 
    // cout << m << endl;
    int answer = 0;
    
    vector<vector<int>> dp(A.size()+1,vector<int>(2*m+1,0));
    // cout << "Here" << endl;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i+1; j < A.size(); j++)
        {
            int diff = A[j] - A[i] + m;
            
            dp[j][diff] = dp[i][diff] + 1;
            
            answer = max(answer,dp[j][diff]);
        }
    }
    return answer+1;
      
    }
};