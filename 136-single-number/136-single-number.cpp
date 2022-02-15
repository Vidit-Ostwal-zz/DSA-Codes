class Solution {
public:
  
  /*XOR with itself leads to nullify of that element*/
    int singleNumber(vector<int>& nums) {
      int answer = 0;
      for (auto x : nums)
        {
          answer = answer ^ x;
        }
      return answer;
    }
};