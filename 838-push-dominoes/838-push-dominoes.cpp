class Solution {
public:
    string pushDominoes(string dominoes) {
        queue<int> q;
      
      for (int i = 0; i < dominoes.length(); i++)
        if (dominoes[i] != '.')
          q.push(i);
      
      while (!q.empty())
      {
        int size = q.size();
        unordered_map<int,char> mp;
        for (int i = 0; i < size; i++)
        {
          int index = q.front();
          q.pop();
          
          if (dominoes[index] == 'L')
          {
            if (mp.find(index-1) != mp.end())
              mp[index-1] = '.';
            else 
              if (index-1>= 0 && dominoes[index-1] == '.')
                mp[index - 1] = 'L';
          }
          
          else if (dominoes[index] == 'R')
          {
            if (mp.find(index+1) != mp.end())
              mp[index+1] = '.';
            else
              if (index + 1 < dominoes.length() && dominoes[index+1] == '.')
                mp[index + 1] = 'R';
          }
        }
        
        auto it = mp.begin();
        while (it != mp.end())
        {
          dominoes[it -> first] = it -> second;
          q.push(it -> first);
          it++;
        }
      }
      return dominoes;
    }
};