class Solution {
public:
    int numDifferentIntegers(string word) {
        set<string> unique;
      for (int i = 0; i < word.length(); i++)
      {
        if (word[i] >= '0' && word[i] <= '9')
        {
          string temp = "";
          while (i < word.length() && word[i] >= '0' && word[i] <= '9')
          {
            if (temp.length() == 0 && word[i] == '0')
            {}
            else
              temp += word[i];
            i++;
          }
          unique.insert(temp);
        }
      }
      return unique.size();
    }
};