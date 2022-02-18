class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<char>st;
      
      if (k == 0)
        return nums;
      
      if (nums.size() == k)
        return "0";
      
      st.push(nums[0]);
      for (int i = 1; i < nums.size(); i++)
      {
        while (!st.empty() && k && nums[i] < st.top())
        {
          st.pop();
          k--;
        }
        st.push(nums[i]);
        
        if (st.size() == 1 && st.top() == '0')
          st.pop();
      }
      
      while (k && !st.empty())
      {
        st.pop();
        k--;
      }
      
      string res = "";
      
      while (!st.empty())
      {
        res += st.top();
        st.pop();
      }
      reverse(res.begin(),res.end());
      if (res.length() == 0)
        return "0";
      return res;
    }
};