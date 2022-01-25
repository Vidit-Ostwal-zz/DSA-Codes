class Solution {
  string to_string_function(vector<char> vect)
  {
    string temp = "";
    for (int i =0 ; i <  vect.size();i++)
    {
      temp += vect[i];
    }
    return temp;
  }
  
public:
    string convert(string s, int numRows) {
        int index = 0;
      unordered_map < int, vector<char>> mp;
      bool reverse = false;
      int indexmp = 0;
      while (index < s.length())
      {
        if (indexmp == 0)
        {
          reverse = false;
        }
        if (indexmp == numRows-1)
        {
          reverse = true;
        }
        mp[indexmp%numRows].push_back(s[index]);
        (reverse) ? indexmp-- : indexmp++;
        index++;
      }
      string answer = "";
      int i = 0; 
      while (i < numRows)
      {
        answer += to_string_function(mp[i]);
        i++;
      }
      return answer;
    }
};