class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      k = k % nums.size();
      if (nums.size() < 2)
      {
        return ;
      }
        vector<int> pre(nums.begin(),nums.begin() + nums.size() - k);
      vector<int> next(nums.begin()+nums.size()-k,nums.end());
      
      pre.insert(pre.begin(),next.begin(),next.end());
      nums= pre;
    }
};