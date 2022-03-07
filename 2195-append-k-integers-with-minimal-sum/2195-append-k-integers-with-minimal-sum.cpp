class Solution {
  /*Classical Binary Search return index if found, returns -1 if not found*/
int Binary_Search(vector<int> nums, int st, int ed,int target)
 {
  while (st <= ed)
  {
   int mid = st + (ed - st) / 2;
    
   if (nums[mid] == target)
    return mid+1;
    
   if (nums[mid] > target)
    ed = mid - 1;
    
   else
    st = mid + 1;
  }
  return ed+1;
}
public:
    long long minimalKSum(vector<int>& nums, int k) {
      set<int> st(nums.begin(),nums.end());
      nums = vector<int>(st.begin(),st.end());
      sort(nums.begin(),nums.end());
      for (int i =0; i < nums.size(); i++)
        cout << nums[i] << " " ;
      
      cout << endl;
      
        long long m = k;
      while (m != (k + Binary_Search(nums,0,nums.size()-1,m)))
      {
        int f = Binary_Search(nums,0,nums.size()-1,m);
        m = (k + f);
        cout <<f << "   "<< m << endl;
      }
      cout << m << endl;
      long long answer = (m*(m+1))/2;
      
      int it = Binary_Search(nums,0,nums.size()-1,m);
      cout <<it << endl;
      for (int i =0; i < it;i++)
      {
        cout << answer << "  " ;
        answer -= nums[i];
      }
      return answer;
    }
};