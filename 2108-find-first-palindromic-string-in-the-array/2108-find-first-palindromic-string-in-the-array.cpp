class Solution {
  bool ispalindrome (string name)
  {
    int st = 0;
    int ed = name.length()-1;
    
    while (st < ed)
    {
      if (name[st] != name[ed])
        return false;
      st++;
      ed--;
    }
    return true;
  }
public:
    string firstPalindrome(vector<string>& words) {
        for (int i = 0; i < words.size(); i++)
          if (ispalindrome(words[i]))
            return words[i];
      
      return "";
    }
};