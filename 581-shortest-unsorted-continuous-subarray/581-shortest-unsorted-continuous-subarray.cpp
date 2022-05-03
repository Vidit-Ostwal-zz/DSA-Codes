class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp(nums.begin(),nums.end());
      
      sort(temp.begin(),temp.end());
      int i = 0;
      while (i < nums.size() && temp[i] == nums[i])
        i++;
      
      int j = nums.size()-1;
      
      while (j >= 0 && temp[j] == nums[j])
        j--;
      
      return (j - i >= 0) ? j-i+1 : 0;
    }
};