class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> answer;
      
      for (int i = 0; i < queries.size(); i++)
      {
        int temp = 0;
        int x = queries[i][0];
        int y = queries[i][1];
        int radius = queries[i][2];
        
        for (int j = 0; j < points.size(); j++)
        {
          int x1 = points[j][0];
          int y1 = points[j][1];
          
          if (radius*radius >= (x1-x)*(x1-x) + (y1-y)*(y1-y))
            temp++;
        }
        answer.push_back(temp);
      }
      return answer;
    }
};