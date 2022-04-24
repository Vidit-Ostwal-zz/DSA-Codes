class Solution {
 
//   void get_set(int x, int y, int r)
//   {
//     cout << "get" << endl;
//     int x_min = x - r;
//     int x_max = x + r;
//     int y_min = y - r;
//     int y_max = y + r;
    
//     for (int i = 0; i <= r; i++)
//       for (int j = 0; j <= r; j++)
//         if ( i*i + j*j <= r*r)
//         {
//           set1.insert({x + i,y + j});
//           set1.insert({x - i,y + j});
//           set1.insert({x - i,y - j});
//           set1.insert({x + i,y - j});
//         }
//   } 
  
public:
    int countLatticePoints(vector<vector<int>>& circles) {
       set<pair<int,int>> set1;
        for (int i = 0; i < circles.size(); i++)
        {
          // get_set(circles[i][0],circles[i][1],circles[i][2]);
          int x = circles[i][0];
          int y = circles[i][1];
          int r = circles[i][2];
          
//           int x_min = x - r;
//           int x_max = x + r;
//           int y_min = y - r;
//           int y_max = y + r;
          
          for (int i = 0; i <= r; i++)
            for (int j = 0; j <= r; j++)
              if ( i*i + j*j <= r*r)
              {
                set1.insert({x + i,y + j});
                set1.insert({x - i,y + j});
                set1.insert({x - i,y - j});
                set1.insert({x + i,y - j});
              }
        }
      return set1.size();
    }
};