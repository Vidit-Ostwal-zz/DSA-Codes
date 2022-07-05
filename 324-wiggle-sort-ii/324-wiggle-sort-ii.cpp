class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
     // Nums is of Odd Size
      sort(nums.begin(),nums.end());
      // reverse(nums.begin(),nums.end());
      vector<int> answer;
      
      if (nums.size() % 2)
      {
        int i = nums.size()/2;
        int j = nums.size() - 1;
        
        while (i >= 0)
        {
          answer.push_back(nums[i--]);

          
          if (j > nums.size()/2)
            answer.push_back(nums[j--]);
          
          // answer.push_back(nums[i++]);
        }
      }
      
      else
      {
        int i = nums.size()/2-1;
        int j = nums.size() - 1;
        
        while (i >= 0)
        {
          answer.push_back(nums[i--]);

          
          if (j >= nums.size()/2)
            answer.push_back(nums[j--]);
          
          // answer.push_back(nums[i++]);
        }
      }
      
      nums = answer;
    }
};