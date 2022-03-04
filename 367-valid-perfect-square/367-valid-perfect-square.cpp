class Solution {
  /*Classical Binary Search return index if found, returns -1 if not found*/
int Binary_Search(int st, int ed,int target)
 {
  while (st <= ed)
  {
   long mid = st + (ed - st) / 2;
    
   if (mid*mid == target)
    return true;
    
   if (mid*mid > target)
    ed = mid - 1;
    
   else
    st = mid + 1;
  }
  return false;
 }
public:
    bool isPerfectSquare(int num) {
        return Binary_Search(1,50000,num);
    }
};