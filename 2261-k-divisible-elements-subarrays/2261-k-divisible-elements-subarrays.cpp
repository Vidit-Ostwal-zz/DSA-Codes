class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
      
      set<vector<int>> st;
      for (int i = 0; i < nums.size(); i++)
      {
      
        int count = 0;
        // int j = i;
        vector<int> temp;
        
        for (int j = i; j < nums.size(); j++)
        {
          temp.push_back(nums[j]);
          
          if (nums[j] % p == 0)
            count++;
          
          if (count <= k)
            st.insert(temp);
          else
            break;
        }
      }
      
      return st.size();
    }
};