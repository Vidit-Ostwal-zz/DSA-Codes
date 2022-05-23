class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> A;
      vector<int> B;
      vector<int> C;
      
      for (int i = 0; i < s.length(); i++)
      {
        if (s[i] == 'a')
          A.push_back(i);
        else if (s[i] == 'b')
          B.push_back(i);
        else
          C.push_back(i);
      }
      
      int answer = 0;
      
      for (int i = 0; i < s.length(); i++)
      {
        if (s[i] == 'a')
        {
          int indexB = upper_bound(B.begin(),B.end(),i)-B.begin();
          int indexC = upper_bound(C.begin(),C.end(),i)-C.begin();
          
          if (indexB < B.size() && indexC < C.size())
            answer += s.length() - (max(B[indexB],C[indexC]));
        }
        else if (s[i] == 'b')
        {
          int indexA = upper_bound(A.begin(),A.end(),i)-A.begin();
          int indexC = upper_bound(C.begin(),C.end(),i)-C.begin();
          
          if (indexA < A.size() && indexC < C.size())
            answer += s.length() - (max(A[indexA],C[indexC]));
        }
        else
        {
          int indexB = upper_bound(B.begin(),B.end(),i)-B.begin();
          int indexA = upper_bound(A.begin(),A.end(),i)-A.begin();
          
          if (indexB < B.size() && indexA < A.size())
            answer += s.length() - (max(B[indexB],A[indexA]));
        }
        // cout << answer << endl;
      }
      return answer;
    }
};