class Solution {
public:
    long long appealSum(string s) {
        
      
//       long long answer = 0;
//       for (int i = 0; i < s.length(); i++)
//       {
//         unordered_map<char,int> u1;
//         for (int j = i; j < s.length(); j++)
//         {
//           u1[s[j]]++;
//           answer += u1.size();
          
//           if (u1.size() == 26)
//           {
//             answer += (long long)26*(s.length() - j - 1);
//             break;
//           }
//         }
//       }
//       return answer;
      
      long long curr = 0;
      long long res = 0;
      unordered_map<char,int> u1;
      for (int i = 0; i < s.length(); i++)
      {
        curr += i + 1 - u1[s[i]];
        res += curr;
        u1[s[i]] = i+1;
      }
      return res;
    }
};