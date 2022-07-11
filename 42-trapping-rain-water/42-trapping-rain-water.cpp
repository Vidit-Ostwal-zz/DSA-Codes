class Solution {
  int TwoPointerApproach (vector<int> &height)
  {
    int st = 0;
    int ed = height.size()-1;
    
    int left_max = 0;
    int right_max = 0;
    
    int rain_water = 0;
    
    while (st <= ed)
    {
      // Protected form right
      if (height[st] <= height[ed])
      {
        rain_water += max(0,left_max - height[st]);
        left_max = max(left_max,height[st]);
        st++;
      }
      // Protected from left
      else
      {
        rain_water += max(0,right_max- height[ed]);
        right_max = max(right_max,height[ed]);
        ed--;
      }
    }
    return rain_water;
  }
public:
    int trap(vector<int>& height) {
        //Intution at a particular index it will store the min(max element in the left side, max element in the right);
      // thus probelm comes down to the basic question where at a particular index we need to find max element in the right hand side and 
      // max element at the left hand side;
      
//       int n = height.size();
      
//       vector<int> left_max(n,0);
//       vector<int> right_max(n,0);
      
//       int lemax = 0;
//       for (int i = 0; i < height.size(); i++)
//       {
//         left_max[i] = lemax;
//         lemax = max(lemax,height[i]);
//       }
      
//       int rimax = 0;
//       for (int i = height.size()-1; i >= 0; i--)
//       {
//         right_max[i] = rimax;
//         rimax = max(rimax,height[i]);
//       }
      
//       int rain_water = 0;
      
//       for (int i = 0; i < height.size(); i++)
//       {
//         int max_rain = min(left_max[i],right_max[i]);
        
//         if (max_rain > height[i])
//           rain_water += max_rain - height[i];
//       }
//       return rain_water;
      
      return TwoPointerApproach(height);
    }
};