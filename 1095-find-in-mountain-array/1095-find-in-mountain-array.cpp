/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
  int find_peak(MountainArray &mountainArr)
  {
    int st =0;
    int ed = mountainArr.length()-1;
    int ln =  mountainArr.length();
    
    while (st <= ed)
    {
      int mid = st + (ed-st)/2;
      
      int temp = mountainArr.get(mid);
      
      if (mid+1 < ln && temp >  mountainArr.get(mid+1) && mid > 0 && temp > mountainArr.get(mid-1))
        return mid;
      
      else if (temp <  mountainArr.get(mid+1))
        st = mid+1;
      
      else
        ed = mid -1;
    }
    return -1;
  }
  
  /*Classical Binary Search return index if found, returns -1 if not found*/
/*Two while loops will handle the repeating elements cases*/
int Binary_Search(MountainArray &mountainArr, int st, int ed,int target)
 {
  while (st <= ed)
  {
   int mid = st + (ed - st) / 2;
    
   if (mountainArr.get(mid)== target)
    return mid;
    
   if (mountainArr.get(mid) > target)
    ed = mid - 1;
    
   else
    st = mid + 1;
  }
  return -1;
 }
  
  
  int Binary_Search1(MountainArray &mountainArr, int st,int target)
 {
    int ed = mountainArr.length()-1;
  while (st <= ed)
  {
   int mid = st + (ed - st) / 2;
    
   if (mountainArr.get(mid)== target)
    return mid;
    
   if (mountainArr.get(mid) > target)
    st = mid + 1;
    
   else
    ed = mid - 1;
  }
  return -1;
 }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int index = find_peak(mountainArr);
      cout << index << endl;
      if (Binary_Search(mountainArr,0,index,target) != -1)
        return Binary_Search(mountainArr,0,index,target);
      
      return Binary_Search1(mountainArr,index+1,target);
    }
};