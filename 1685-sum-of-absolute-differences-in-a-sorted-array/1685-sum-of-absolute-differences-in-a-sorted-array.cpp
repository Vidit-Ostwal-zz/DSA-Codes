class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> prefix;
      
      for (int i = 0; i < nums.size(); i++)
      {
        prefix.push_back((i > 0) ? prefix[i-1] + nums[i] : nums[i]);
      }
      
      vector<int> answer;
      
      for (int i = 0; i < nums.size(); i++)
      {
        int left = (i > 0) ? i*nums[i] - prefix[i-1] : 0;
        int right = (i == nums.size()-1) ? 0 : (prefix[prefix.size()-1] - prefix[i] - (nums[i]* (nums.size()-i-1)));
        answer.push_back(left+right);
                                                                                                                               
      }
      return answer;
    }
};