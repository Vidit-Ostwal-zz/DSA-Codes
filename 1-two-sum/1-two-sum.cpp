class Solution {
public:
  /*Two Pointer Approach
  Hash Map cannot be used because we map same values twice either use a vector of hash map
  But that will be too much complicated
  We need another thing in which these two things are paired up in some manner*/
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> v;
        for (int i = 0; i < nums.size(); i++)
        {
          v.push_back(make_pair(nums[i],i));
        }
        sort(v.begin(),v.end());
        
        int start = 0;
        int end = nums.size() -1;
        
        while (start <= end)
        {
          int sum  = v[start].first + v[end].first;
          
          if (sum  == target)
          {
            vector<int> answer;
            answer.push_back(v[start].second);
            answer.push_back(v[end].second);
            return answer;
          }
          else if (sum > target)
            end--;
          
          else
            start++;
          
        }
      return {};
    }
};