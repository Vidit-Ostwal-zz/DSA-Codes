class Solution {
  int Binary_Search(vector<int> nums, int target, bool is_left)
  {
    int st = 0;
    int ed = nums.size() - 1;
    
    int answer = -1;
    while (st <= ed)
    {
      int mid = st + ((ed - st) / 2);
      if (nums[mid] == target)
      {
        answer = mid;
        if (is_left)
          ed = mid - 1;
        else
          st = mid + 1;
      }
      
      else if (nums[mid] > target)
        ed = mid - 1;
      
      else
        st = mid +1;
    }
    return answer;
  }
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
      int left = Binary_Search(nums,target,true);
      if (left == -1)
        return {};
      
      int right = Binary_Search(nums,target,false);
      vector<int> answer;
      for (int i = left; i <= right; i++)
        answer.push_back(i);
      
      return answer;
    }
};