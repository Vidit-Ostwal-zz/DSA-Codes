class Solution {
  void swap(int&A,int&B)
  {
    int temp = A;
    A = B;
    B = temp;
  }
  
  /*O(N^2) and O(1)*/
  vector<int> bubble_sort(vector<int> nums)
  {
    for (int i = 0; i < nums.size()-1; i++)
    {
      bool flag = true;
      for (int j =1; j < nums.size()-i; j++)
      {
        if (nums[j] < nums[j-1])
        {
            swap(nums[j],nums[j-1]);
          flag = false;
        }
      }
      if (flag)
        return nums;
    }
    return nums;
  }
  
public:
    vector<int> sortArray(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      return nums;
        return bubble_sort(nums);
    }
};