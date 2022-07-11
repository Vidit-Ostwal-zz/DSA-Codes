class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
      int N = heights.size();
      
      vector<int> left_breaker(N,0);
      vector<int> right_breaker(N,0);
      
      stack<pair<int,int>> left;
      stack<pair<int,int>> right;
      
      for (int i = 0; i < heights.size(); i++)
      {
        while (!left.empty() && left.top().first >= heights[i])
          left.pop();
        
        if (left.empty())
          left_breaker[i] = -1;
        else
          left_breaker[i] = left.top().second;
        
        left.push(make_pair(heights[i],i));
      }
      
      for (int i = N-1; i >= 0; i--)
      {
        while (!right.empty() && right.top().first >= heights[i])
          right.pop();
        
        if (right.empty())
          right_breaker[i] = N;
        else
          right_breaker[i] = right.top().second;
        
        right.push(make_pair(heights[i],i));
      }
      
      int max_histo = 0;
      
      for (int i = 0; i < N; i++)
        max_histo = max(max_histo,heights[i]*(right_breaker[i]-left_breaker[i]-1));
      
      return max_histo;
    }
};