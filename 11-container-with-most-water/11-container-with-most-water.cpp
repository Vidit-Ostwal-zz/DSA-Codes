class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
      int end = height.size() -1;
      
      int maxi = INT_MIN;
      while (start < end)
      {
        int curr_area = (end - start) * min(height[start],height[end]);
        
        maxi = max(curr_area,maxi);
        
        if (height[start] < height[end])
          start++;
        else
          end--;
      }
      return maxi;
    }
};