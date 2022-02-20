class Solution {
  int merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
      int sum = 0;
      vector<vector<int>> final_vector;
      int x1 = intervals[0][0];
      int x2 = intervals[0][1];
      
      for (int i = 0; i < intervals.size(); i++)
      {
        x1 = intervals[i][0];
        x2 = intervals[i][1];
        
        while(i+1 < intervals.size() && intervals[i+1][0] <= x2)
        {
          x2 = max(x2,intervals[i+1][1]);
          i++;
        }
        vector <int> temp{x1,x2};
        sum += x2 - x1 + 1;
        final_vector.push_back(temp); 
      }
      
    
      return sum;
    }
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
      vector<vector<int>> final_vector;
      for (int i = 0; i < timeSeries.size(); i++)
        final_vector.push_back({timeSeries[i],timeSeries[i]+duration-1});
        
      return merge(final_vector);
    }
};