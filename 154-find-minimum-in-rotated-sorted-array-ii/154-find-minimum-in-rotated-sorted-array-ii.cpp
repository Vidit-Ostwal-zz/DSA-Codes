class Solution {
  /*Returns the Peak element in roated sorted array, point where the pivot occurs
 If no pivot occurs than, which means it's not rotated even return the first element*/
 int Binary_Search_Peak(vector<int> nums)
 {
 int st = 0; 
 int ed = nums.size() -1;
  
 while (st <= ed)
 {
   while (st < ed && nums[st] == nums[st+1])
      st++;
   
   while (st < ed && nums[ed] == nums[ed-1])
      ed--;
   
   int mid = st + (ed - st)/2;
   
  if (mid + 1 < nums.size() && nums[mid] > nums[mid+1])
  return mid;
   
  if (mid - 1 >= 0 && nums[mid-1] > nums[mid])
  return mid-1;
   
  else if (nums[mid] > nums[ed])
  st = mid + 1;
   
  else 
  ed = mid - 1;
 }
 return -1;
 }
  
public:
    int findMin(vector<int>& nums) {
      int index = Binary_Search_Peak(nums);
      return nums[(index+1) % nums.size()];
    }
};