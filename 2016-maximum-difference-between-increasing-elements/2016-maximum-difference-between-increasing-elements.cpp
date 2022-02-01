class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        /*Parent Question : Find the maximum difference between any two element of the array
        Finding maximum and minimum would work
        In this you have to find the minimum element you have found since and also the maximum differnece one can find since*/
      
      int max_difference_so_far = -1;
      int min_element  = nums[0];
      
      for (int i = 1; i < nums.size(); i++)
      {
        if (nums[i] != min_element)
        {
           max_difference_so_far = max(max_difference_so_far,nums[i] - min_element);
        min_element  = min(min_element,nums[i]);
        }
       
      }
      return max_difference_so_far;
    }
};