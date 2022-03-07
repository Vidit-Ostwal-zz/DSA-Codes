class Solution {
  
  /*The pivot element will be at the right place in the first place*/
  /*In merge Sort even if the vector is sorted it will go till very end, in this
  it will not*/
  void quick_sort(vector<int>& nums, int st, int ed)
  {
    if (st >= ed)
      return;
    
    int s = st;
    int e = ed;
    int m = (s + e) / 2;
    int pivot = nums[m];
    
    while (s <= e)
    {
      while(nums[s] < pivot)
        s++;
      
      while (nums[e] > pivot)
        e--;
      
      if (s <= e)
      {
        int temp = nums[s];
        nums[s] = nums[e];
        nums[e] = temp;
        s++;
        e--;
      }
    }
    quick_sort(nums,st,e);
    quick_sort(nums,s,ed);
  }
  
public:
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums,0,nums.size()-1);
      return nums;
    }
};