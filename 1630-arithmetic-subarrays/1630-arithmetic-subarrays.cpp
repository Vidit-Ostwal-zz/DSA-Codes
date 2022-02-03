class Solution {
   bool check(vector<int> nums, int end_index, int start_index)
  {
    vector<int> temp(nums.begin() + start_index, nums.begin() +end_index + 1);
    sort(temp.begin(),temp.end());
    
    for (int i = 2 ; i < temp.size(); i++)
    {
      if (temp[i] - temp[i-1] != temp[1] - temp[0])
        return false;
    }
    return true;
  }
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> final_vector;
      for (int i =0; i < l.size(); i++)
        final_vector.push_back(check(nums,r[i],l[i]));
      
      return final_vector;
    }
};