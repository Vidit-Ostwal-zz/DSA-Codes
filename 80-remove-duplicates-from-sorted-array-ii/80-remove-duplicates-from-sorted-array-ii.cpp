class Solution {
  int remove(vector<int> &nums)
  {
    int i = 1;
    for (int j = 2; j < nums.size(); j++)
    {
      if ((nums[j] == nums[i] && nums[j] != nums[i-1]) || (nums[j] != nums[i] && nums[j] != nums[i-1]))
      {
        cout << j << endl;
        nums[i+1] = nums[j];
        i++;
      }
    }
    return i+1;
  }
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2)
          return nums.size();
      
      return remove(nums);
    }
};