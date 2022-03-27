class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
      
      for (int i = 0; i < mat.size(); i++)
      {
        int count = 0;
        for (int j=  0; j < mat[i].size(); j++)
          count+= mat[i][j];
        
        pq.push(make_pair(count,i));
      }
      
      vector<int> answer;
      while (k)
      {
        answer.push_back(pq.top().second);
        pq.pop();
        k--;
      }
      return answer;
    }
};