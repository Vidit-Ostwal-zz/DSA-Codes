vector<int> Bubble_Sort (vector<int>& nums)
  {
    /*run the steps length -1 times*/
    for (int i = 0; i < nums.size()-1;i++)
    {
      bool swapped = true;
      for (int j = 1; j <= nums.size()-1-i ; j++)
      {
        /*swap if lesser than previous*/
        if (nums[j] < nums[j-1])
        {
          int temp = nums[j];
          nums[j] = nums[j-1];
          nums[j-1] = temp;
          swapped = false;
        }
      }
      if (swapped)
      {
        return nums;
      }
    }
    return nums;
  }
