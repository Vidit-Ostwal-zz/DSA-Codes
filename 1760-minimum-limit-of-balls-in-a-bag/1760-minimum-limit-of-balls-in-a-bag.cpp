class Solution {
  int get_bags(vector<int> nums, int max_weight)
  {
    int bag_required = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] % max_weight == 0)
        bag_required += nums[i]/max_weight;
      
      else
        bag_required += nums[i]/max_weight + 1;
    }
    return bag_required;
  }
  
  
  int Binary_Search(int st, int ed, int target,vector<int> nums)
  {
    int answer = -1;
    while (st <= ed)
    {
      int mid = st + (ed - st)/ 2;
      int mid_bag = get_bags(nums,mid);
      cout << mid <<  "    " << mid_bag << endl;
      if (mid_bag <= target)
      {
        answer = mid;
        ed = mid - 1;
      }
      else if (mid_bag > target)
        st = mid + 1;
    }
    return answer;
  }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
      sort(nums.begin(),nums.end());
      return Binary_Search(1,nums[nums.size()-1],maxOperations+nums.size(),nums);
    }
};