class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
      set<int> x_points;
        for (int i = 0; i < points.size(); i++)
          x_points.insert(points[i][0]);
      
      vector<int> x_vector(x_points.begin(),x_points.end());
      sort(x_vector.begin(),x_vector.end());
      
      
      int maxi = 0;
      for (int i = 1; i < x_vector.size(); i++)
        maxi = max(maxi,x_vector[i] - x_vector[i-1]);
      
      return maxi;
    }
};