class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int,int> map1;
      
      for (int i = 0; i < items1.size(); i++)
        map1[items1[i][0]] += items1[i][1];
      
      for (int i = 0; i < items2.size(); i++)
        map1[items2[i][0]] += items2[i][1];
      
      vector<vector<int>> answer;
      
      auto it = map1.begin();
      
      while (it != map1.end())
      {
        answer.push_back({it -> first, it -> second});
        it++;
      }
      
      return answer;
    }
};