class Solution {
  /*Returns the Peak element in roated sorted array, point where the pivot occurs
 If no pivot occurs than, which means it's not rotated even return the first element*/
 int Binary_Search_Peak(vector<int> nums)
 {
 int st = 0; 
 int ed = nums.size() -1;
  
 while (st <= ed)
 {
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
 return st;
 }
  
  /*Classical Binary Search return index if found, returns -1 if not found*/
bool Binary_Search(vector<int> nums, int st, int ed,int target)
 {
  while (st <= ed)
  {
    while (st < ed && nums[st] == nums[st+1])
      st++;
    
    while (st < ed && nums[ed] == nums[ed-1])
      ed--;
    
   int mid = st + (ed - st) / 2;
    
   if (nums[mid] == target)
    return true;
    
   if (nums[mid] > target)
    ed = mid - 1;
    
   else
    st = mid + 1;
  }
  return false;
 }
  
public:
    bool search(vector<int>& nums, int target) {
        int pivot = Binary_Search_Peak(nums);
      cout << pivot << endl;
      
      int index1 = Binary_Search(nums,0,pivot,target);
      cout << index1 << endl;
      
      if (index1 == false)
        return Binary_Search(nums,pivot+1,nums.size()-1,target);
      
      return index1;
      
    }
};