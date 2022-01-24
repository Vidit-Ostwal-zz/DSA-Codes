class Solution {
  int binary_search(vector<int> nums, int target, bool flag)
  {
    int start = 0;
    int end = nums.size()-1;
    int temp_answer = -1;
    while (start <= end)
    {
      int mid = (start + end) / 2;
      
      if (nums[mid] == target)
      {
        temp_answer = mid;
        if (flag)
        {
          end  = mid -1;
        }
        else
        {
          start = mid +1;
        }
      }
      else if (nums[mid] > target)
      {
        end = mid - 1;
      }
      else
      {
        start = mid + 1;
      }
    }
    return temp_answer;
  }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> final_vector ;
      final_vector.push_back(binary_search(nums,target,true));
      final_vector.push_back(binary_search(nums,target,false));
      return final_vector;
    }
};