class Solution {
public:
    int maxProduct(vector<int>& nums) {
      
      if (nums.size() == 0)
        return 0;
      
      int maxi = nums[0];
      int mini = nums[0];
      int answer = nums[0];
      for (int i =1; i < nums.size(); i++)
      {
        
        if (nums[i] < 0)
        {
          int temp = maxi;
          maxi = mini;
          mini = temp;
        }
        
        maxi = max (nums[i],maxi*nums[i]);
        mini = min (nums[i],mini*nums[i]);
        answer = max(answer,maxi);
      }
      return answer;
    }
};