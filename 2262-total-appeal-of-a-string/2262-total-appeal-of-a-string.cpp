class Solution {
public:
    long long appealSum(string s) {
        // See Notes
      
      /*this will store the contribution of just one index, we need to sum up all the elements in this, which will give the final answer*/
      vector<long long> answer;
      
      /*Map will keep the trakc of previous index*/
      unordered_map<char,int> u1;
      
      /*will keep the final answer*/
      long long res = 1;
      
      answer.push_back(1);
      u1[s[0]] = 1;
      
      for (int i = 1; i < s.length(); i++)
      {
        int temp = answer[i-1] + i+1 - u1[s[i]];
        res += temp;
        answer.push_back(temp);
        u1[s[i]] = i+1;
      }
      return res;
    }
};