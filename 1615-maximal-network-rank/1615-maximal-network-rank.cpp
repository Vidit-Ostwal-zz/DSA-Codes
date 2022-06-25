class Solution {
  void Show_Map(unordered_map<int,unordered_map<int,int>> map)
 {
  auto it = map.begin();
  cout << "Printing Map" << endl;
  cout << "-----------------" << endl;
  cout << "Key" << "     " << "Value" << endl;
  while (it != map.end())
  {
   cout << it-> first << "   " << (it -> second).size() << endl;
   it++;
  }
  cout << "Printing Map Over" << endl;
  }
  
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,unordered_map<int,int>> map1;
      
      for (int i = 0; i < roads.size(); i++)
      {
        int st = roads[i][0];
        int ed = roads[i][1];
        
        map1[st][ed]++;
        map1[ed][st]++;
      }
      
      // Show_Map(map1);
      
      int answer = 0;
      
      for (int i = 0; i < n; i++)
      {
        for (int j = i+1 ; j < n; j++)
        {
          int temp = (map1[i].size() + map1[j].size());
          
          // cout << "I_Index_Size   ---->>>> " <<  map1[i].size() << "     J_Index_Size ---->>>> " << map1[j].size() << endl;
          
          if (map1[i][j])
          {
            temp--;
          }
          else
          {
            map1[i].erase(j);
          }
          
          // cout << i << "    " << j << "     " << temp << endl;
          
          answer = max(temp,answer);
        }
      }
      return answer;
    }
};