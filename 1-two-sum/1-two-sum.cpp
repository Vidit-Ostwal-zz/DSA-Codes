class Solution {
  vector<int> ClosingWindow(vector<vector<int>> A, int target)
  {
    int i = 0;
    int j = A.size()-1;
    
    while (i < j)
    {
      int temp = A[i][0] + A[j][0];
      
      if (temp == target)
      {
        vector<int> B;
        B.push_back(A[i][1]);
        B.push_back(A[j][1]);
        return B;
      }
      else if (temp > target)
        j--;
      else
        i++;
    }
    return {-1};
  }
  
  vector<int> Hash_map(vector<int> nums, int target)
  {
    unordered_map<int,int> u1;
    vector<int> B;
    for (int i = 0; i < nums.size(); i++)
    {
      if (u1.find(target-nums[i]) != u1.end())
      {
        B.push_back(i);
        B.push_back(u1[target-nums[i]]);
        return B;
      }
      u1[nums[i]] = i;
    }
    return {0};
  }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      
      return Hash_map(nums,target);
      
      
      
        vector<vector<int>> A;
      for (int i = 0; i < nums.size(); i++)
      {
        vector<int> temp;
        temp.push_back(nums[i]);
        temp.push_back(i);
        A.push_back(temp);
      }
      
      // Indices Will remain Preserved;
      sort(A.begin(),A.end());
      
      return ClosingWindow(A,target);
    }
};