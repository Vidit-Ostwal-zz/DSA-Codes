class Solution {
  vector<vector<int>> dp_1;
  vector<vector<int>> dp_2;
  vector<vector<int>> dp;
  int max_product(vector<int> num1, vector<int> num2, int i, int j, bool flag)
  {
    if (i == num1.size() || j == num2.size())
      return (!flag) ?  INT_MIN : 0;
    
    if (flag)
    {
      if (dp_1[i][j] != -1)
        return dp_1[i][j];
      
      int temp = max_product(num1,num2,i+1,j+1,flag);
      return dp_1[i][j] = max(max(num1[i]*num2[j] + temp,temp),max(max_product(num1,num2,i,j+1,flag),max_product(num1,num2,i+1,j,flag)));
    }
    else
    {
      if (dp_2[i][j] != -1)
        return dp_2[i][j];
      return dp_2[i][j] = max(max(num1[i]*num2[j] + max_product(num1,num2,i+1,j+1,!flag),max_product(num1,num2,i+1,j+1,flag)),max(max_product(num1,num2,i,j+1,flag),max_product(num1,num2,i+1,j,flag)));
    }
  }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
//     dp_1 = vector<vector<int>> (nums1.size()+1,vector<int>(nums2.size()+1,-1));
//       dp_2 = vector<vector<int>> (nums1.size()+1,vector<int>(nums2.size()+1,-1));
    
       dp = vector<vector<int>> (nums1.size()+1,vector<int>(nums2.size()+1,-1));
      // return max_product(nums1,nums2,0,0,false);
      
      for (int i = 0; i < dp.size(); i++)
      {
        for (int j =  0; j < dp[0].size(); j++)
        {
          if (i == 0 || j == 0)
            dp[i][j] = 0;
          
          else 
            dp[i][j] = max(max(nums1[i-1]*nums2[j-1]+dp[i-1][j-1],dp[i-1][j-1]),max(dp[i-1][j],dp[i][j-1]));
          
          // cout << dp[i][j] << "  ";
        }
        // cout << endl;
      }
      
      if (dp[nums1.size()][nums2.size()] > 0)
        return dp[nums1.size()][nums2.size()];
      int zero_count1 = 0;
      int neg1 = 0;
      int zero_count2 = 0;
      int neg2 = 0;
      
      for (int i = 0; i < nums1.size(); i++)
      {
        if (nums1[i] < 0)
          neg1++;
        else if (nums1[i] == 0)
          zero_count1++;
      }

      for (int i = 0; i < nums2.size(); i++)
      {
        if (nums2[i] < 0)
          neg2++;
        else if (nums2[i] == 0)
          zero_count2++;
      }
      
      if (zero_count1 ||zero_count2)
        return dp[nums1.size()][nums2.size()];
      
      if (neg1 == nums1.size() ||neg2 == nums2.size())
      {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        return max(nums1[nums1.size()-1]*nums2[0],max(nums2[nums2.size()-1]*nums1[0],nums1[0]*nums2[0]));
      }
     return -1;
    }
};