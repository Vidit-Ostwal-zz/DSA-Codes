class Solution {
public:
  
  void swap(int&A, int&B)
  {
    int temp = A;
    A = B;
    B = temp;
  }
  
  void reverse(vector<int>&nums,int index)
  {
    int end = nums.size()-1;
    
    while (index < end)
    {
      swap(nums[index],nums[end]);
      index++;
      end--;
    }
  }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size()-1;
      while (n>0 && nums[n] <= nums[n-1])
      {
        n--;
      }
      int the_index;
      int answer = INT_MAX;
      if (n == 0)
      {
        sort(nums.begin(),nums.end());
        return ; 
      }
        
      for (int i = n; i < nums.size(); i++)
      {
        if (nums[i] > nums[n-1])
        {
          answer = min(answer,nums[i]);
          the_index = i;
        }
      }
      
      swap(nums[n-1],nums[the_index]);
      reverse(nums,n);
    }
};