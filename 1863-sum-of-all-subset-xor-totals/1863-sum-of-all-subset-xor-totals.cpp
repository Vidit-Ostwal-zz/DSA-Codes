class Solution {
  int recursive_solution(vector<int> nums, int index, int temp_answer)
  {
    if (index == nums.size())
      return temp_answer;
    
    return recursive_solution(nums,index+1,temp_answer ^ nums[index]) + recursive_solution(nums,index+1,temp_answer);
  }
public:
    int subsetXORSum(vector<int>& nums) {
        return recursive_solution(nums,0,0);
    }
};