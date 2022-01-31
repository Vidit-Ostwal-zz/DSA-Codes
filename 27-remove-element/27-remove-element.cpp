class Solution {
  int switch_non_val(vector<int>&nums, int val)
  {
    int i = 0;
      for (int j = 0; j < nums.size();j++)
      {
        if (nums[j] != val)
        {
          nums[i] = nums[j];
          i++;
        }
      }
      return i;
  }

  int switch_val (vector<int>&nums, int val)
  {
    int i = 0;
    int n = nums.size();
    while (i < n)
    {cout << i << "   " << n <<  endl;
      if (nums[i] == val)
      {
        nums[i] = nums[n-1];
        n--;
      }
      else
      {
        i++;
      }
     cout << i << "   " << n <<  endl;
    }
    return n;
  }
public:
    int removeElement(vector<int>& nums, int val) {
      return switch_val(nums,val);
        return switch_non_val(nums,val);
    }
};