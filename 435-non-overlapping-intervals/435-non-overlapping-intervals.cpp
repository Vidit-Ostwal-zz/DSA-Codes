#define pi pair<int,int> 

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      int n = intervals.size();  
      vector<pi> vect(n,{0,0});
      
      for (int i = 0; i < n; i++)
      {
        vect[i].first = intervals[i][1];
        vect[i].second = i;
      }
      
      sort(vect.begin(),vect.end());
      
      int max_meetings = 1;
      int time = vect[0].first;
      
      for (int i = 1; i < vect.size(); i++)
      {
        int endtime = vect[i].first;
        int starttime = intervals[vect[i].second][0];
        
        if (starttime >= time)
        {
          max_meetings++;
          time = endtime;
        }
      }
      return intervals.size() - max_meetings;
    }
};