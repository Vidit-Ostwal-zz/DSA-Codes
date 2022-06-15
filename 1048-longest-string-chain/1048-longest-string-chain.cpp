class Solution {
  static bool comparestrings(string A, string B)
  {
    return A.length() < B.length();
  }
  
//   void show_vector(vector<string> vect)
// {
//   for (auto&it:vect)
//   {
//     cout << it << endl;
//     // cout << it.first << "  " << it.second << endl;
//   }
// }

public:
    int longestStrChain(vector<string>& words) {
      
      sort(words.begin(),words.end(),comparestrings);
      unordered_map<string,int> stringmap;
      int max_length = 1;
      for (int i = 0; i < words.size(); i++)
        stringmap[words[i]]++;
      
      for (int i = words.size()-1; i >= 0; i--)
      {
        string curr = words[i];
        
        for (int j = 0; j < curr.length(); j++)
        {
          string left = curr.substr(0,j);
          string right = curr.substr(j+1);
          
          string concat = left + right;
          
          if (stringmap.find(concat) != stringmap.end())
          {
            stringmap[concat] = max(stringmap[concat],1 + stringmap[curr]);
            max_length = max(max_length,stringmap[concat]);
          }
        }
      }
      return max_length;
    }
};