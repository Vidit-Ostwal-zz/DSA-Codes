class Solution {
  void swap (int &a, int &b)
  {
    int temp = a;
    a = b;
    b = temp;
  }
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0;
      for (int j = 0; j < nums.size(); j++)
      {
        if (nums[j]%2 == 0)
          swap(nums[j],nums[i++]);
      }
      return nums;
    }
};