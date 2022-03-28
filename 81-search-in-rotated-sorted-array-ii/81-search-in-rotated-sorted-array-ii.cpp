class Solution {
  int rotated(vector<int> nums)
  {
    int st = 0;
    int ed = nums.size()-1;
    
    while (st <= ed)
    {
      int mid = (st + ((ed - st)/2));
      
      if (mid+1 < nums.size() && nums[mid] > nums[mid+1])
        return mid;
      
      else if (mid-1 >= 0 && nums[mid] < nums[mid-1])
        return mid-1;
      
      else if (nums[mid] <= nums[ed])
        ed = mid - 1;
      
      else
        st = mid + 1;
    }
    return st;
  }
  
  /*Classical Binary Search return index if found, returns -1 if not found*/
int Binary_Search(vector<int> nums, int st, int ed,int target)
 {
  while (st <= ed)
  {
   int mid = st + (ed - st) / 2;
    
   while (st < ed && nums[st] == nums[st+1])
      st++;
    
   while (st < ed && nums[ed] == nums[ed-1])
      ed--;
    
   if (nums[mid] == target)
    return mid;
    
   if (nums[mid] > target)
    ed = mid - 1;
    
   else
    st = mid + 1;
  }
  return -1;
}
public:
    bool search(vector<int>& nums, int target) {
        int index = (nums.size() == 1) ? 0 : rotated(nums);
      cout << index << endl;
     if (Binary_Search(nums,0,index,target) != -1)
       return true;
      
      return (Binary_Search(nums,index+1,nums.size()-1,target) != -1) ? true:false;
    }
};