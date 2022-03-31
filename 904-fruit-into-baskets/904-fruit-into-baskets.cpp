class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> map;
      
      int answer = 0;
      int j = 0;
      for (int i = 0; i < fruits.size(); i++)
      {
        map[fruits[i]]++;
        
        while (map.size() > 2)
        {
          map[fruits[j]]--;
          
          if (map[fruits[j]] == 0)
            map.erase(fruits[j]);
          
          j++;
        }
        answer = max(answer,i-j+1);
      }
      return answer;
    }
};