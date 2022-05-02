class Solution {
  bool isVowel(char ch)
  {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
  }
public:
    long long countVowels(string word) {
      
      long long res = 0;
      long long curr = 0;
      
      for (int i = 0; i < word.length(); i++)
      {
        if (isVowel(word[i]))
          curr += (i+1);
        
        res += curr;
      }
      return res;
    }
};