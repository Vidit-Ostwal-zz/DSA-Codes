class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
      
      int count = 0;
      for (int i = 0; i < words.size(); i++)
        {
          string temp = s.substr(0,words[i].length());
        // cout << temp <<  "    " << words[i].compare(temp) << endl;
          if (words[i].compare(temp) == 0)
            count++;
        }
      return count;
    }
};