class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<bool>> visited (image.size(),vector<bool>(image[0].size(),true));
      
      queue<pair<int,int>> q;
      q.push(make_pair(sr,sc));
  
      int initial = image[sr][sc];
      while (!q.empty())
      {
        pair<int,int> pt = q.front();
        
        int row = pt.first;
        int col = pt.second;
        visited[row][col] = false;
        q.pop();
        
       if (image[row][col] == initial)
         image[row][col] = newColor;
        
       if (row > 0 && image[row-1][col] == initial && visited[row-1][col])
       {
         image[row-1][col] = newColor;
         q.push(make_pair(row-1,col));
       }
      
       if (row +1 < image.size() && image[row +1][col] == initial && visited[row+1][col])
       {
         image[row +1][col] = newColor;
         q.push(make_pair(row+1,col));
       }
        
       if (col > 0 && image[row][col-1]  == initial && visited[row][col-1])
       {
          image[row][col-1] = newColor; 
         q.push(make_pair(row,col-1));
       }
         
        
       if (col+1 < image[0].size() && image[row ][col+1] == initial && visited[row][col+1])
       {
         image[row][col+1] = newColor;
         q.push(make_pair(row,col+1));
       }
      }
      return image;
    }
};