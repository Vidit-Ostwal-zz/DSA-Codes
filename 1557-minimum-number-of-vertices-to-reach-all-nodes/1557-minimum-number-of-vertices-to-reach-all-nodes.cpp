class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n,true);
      
      for (int i = 0; i < edges.size(); i++)
        visited[edges[i][1]] = false;
      
      vector<int> answer;
      
      for (int i = 0; i < visited.size(); i++)
        if (visited[i])
          answer.push_back(i);
      
      return answer;
    }
};