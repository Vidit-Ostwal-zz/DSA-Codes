class Solution {
public:
    int trap(vector<int>& height) {
        //Intution at a particular index it will store the min(max element in the left side, max element in the right);
      // thus probelm comes down to the basic question where at a particular index we need to find max element in the right hand side and 
      // max element at the left hand side;
      
      int n = height.size();
      
      vector<int> left_max(n,0);
      vector<int> right_max(n,0);
      
      int lemax = 0;
      for (int i = 0; i < height.size(); i++)
      {
        left_max[i] = lemax;
        lemax = max(lemax,height[i]);
      }
      
      int rimax = 0;
      for (int i = height.size()-1; i >= 0; i--)
      {
        right_max[i] = rimax;
        rimax = max(rimax,height[i]);
      }
      
      int rain_water = 0;
      
      for (int i = 0; i < height.size(); i++)
      {
        int max_rain = min(left_max[i],right_max[i]);
        
        if (max_rain > height[i])
          rain_water += max_rain - height[i];
      }
      return rain_water;
    }
};