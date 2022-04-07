class Solution {
  bool isPossible(string temp,vector<int> F)
  {
    for (int i = 0; i < temp.length(); i++)
    {
      if (F[temp[i] - 'a'] == 0)
        return false;
      else
        F[temp[i] - 'a']--;
    }
    return true;
  }
  
  int max_score(vector<string> W, vector<int> F, vector<int>S, int i)
  {
    // cout << i << endl;
    if (i == W.size())
      return 0;
    
    if (isPossible(W[i],F))
    {
      int option1 = max_score(W,F,S,i+1);
      
      int sum = 0;
      
      for (int j = 0; j < W[i].length(); j++)
      {
        sum += S[W[i][j] - 'a'];
        F[W[i][j] - 'a']--;
      }
      
      int option2 = max_score(W,F,S,i+1);
      return max(option1,sum + option2);
    }
    return max_score(W,F,S,i+1);
  }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
      vector<int> freq(26,0);
      
      for (int i = 0; i < letters.size(); i++)
        freq[letters[i] - 'a']++;
      
        return max_score(words,freq,score,0);
    }
};