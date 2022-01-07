class Solution {
public:
  string helper (int index)
  {
    string answer = to_string(index);
    
    if (index % 3 == 0 && index % 5 == 0)
    {
      answer = "FizzBuzz";
      return answer;
    }
    else if (index % 3 == 0)
    {
      answer = "Fizz";
      return answer;
    }
    else if (index % 5 == 0)
    {
      answer = "Buzz";
      return answer;
    }
    return answer;
  }
  
  
  
    vector<string> fizzBuzz(int n) {
      vector<string> final_vector;  
      for (int i = 1 ; i <= n ; i++)
        {
          final_vector.push_back(helper(i));
        }
      return final_vector;
    }
};