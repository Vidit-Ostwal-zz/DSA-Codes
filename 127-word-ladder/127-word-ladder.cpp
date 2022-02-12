class Solution {
  int ladder = 0;
  int bfs(string beginWord, string endWord, unordered_set<string> st)
  {
    queue<string> q;
    
    q.push(beginWord);
    
    while (!q.empty())
    {
      int size = q.size();
      ladder++;
      
      for (int i = 0; i < size ; i++)
      {
        string temp = q.front();
        q.pop();
        
        for(int i = 0; i < temp.length();i++)
        {
          string curr = temp;
          
          for (char ch = 'a'; ch <= 'z' ;ch++)
          {
            curr[i] = ch;
            
            if (curr == temp)
              continue;
            
            if (curr == endWord) return ladder+1;
            
            if (st.count(curr))
            {
              q.push(curr);
              st.erase(curr);
            }
          }
        }
      }
    }
    
    return 0;
  }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
      
      ladder = 0;
      
      for (int i = 0; i < wordList.size();i++)
        st.insert(wordList[i]);
      
      if (st.count(endWord) == 0) return ladder;
      
      return bfs(beginWord,endWord,st);
    }
};