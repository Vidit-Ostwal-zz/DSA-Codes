class Solution {
  string get_log(int n)
  {
    string temp = "";
    
    while (n >0)
    {
      temp = to_string(n%2) + temp;
      n = n /2; 
    }
    return temp;
  }
public:
    int minFlips(int a, int b, int c) {
      string A = get_log(a);
      string B = get_log(b);
      string C = get_log(c);
      int answer = 0;
      int max_length(max(A.length(),max(B.length(),C.length())));
      
      while (max_length != A.length())
      {
        A = "0" + A;
      }
      while (max_length != B.length())
      {
        B = "0" + B;
      }
      while (max_length != C.length())
      {
        C = "0" + C;
      }
      max_length--;
      while (max_length >= 0)
      {
        
        if ((A[max_length] - '0' | B[max_length] - '0') == C[max_length] - '0')
        {
        }
        else
        {
          if (C[max_length] - '0' == 0)
          {
            if (A[max_length] == '1')
              answer ++;
            if(B[max_length] == '1')
              answer++;
          }
          else
            answer++;
        }
        max_length--;
      }
      return answer;
    }
};