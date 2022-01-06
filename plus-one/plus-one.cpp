class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits[digits.size()-1] < 9)
        {
          digits[digits.size()-1] += 1;
          return digits;
        }
      else
      {
        int last_index = digits.size()-1;
        while (last_index >= 0 && digits[last_index] == 9)
        {
          digits[last_index] = 0;
          last_index--;
        }
        if (last_index >= 0)
        {
          digits[last_index] += 1;
        }
        else
        {
          vector<int> temp = {1};
          digits.insert(digits.begin(),temp.begin(),temp.end());
        }
      }
      return digits;
      
    }
};