class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>> pq;
      
      for (int i = 0; i < points.size(); i++)
        pq.push(make_pair(points[i][0]*points[i][0] + points[i][1]*points[i][1],points[i]));
      
      vector<vector<int>> answer;
      while (k)
      {
        answer.push_back(pq.top().second);
        pq.pop();
        k--;
      }
      return answer;
    }
};