class Solution {
  int X[4] = {1,-1,0,0};
  int Y[4] = {0,0,1,-1};
  int n = 0;
  int m = 0;
  
  bool isInside(int x, int y, int n, int m)
  {
    return (x >= 0 && y >= 0 && x < n && y < m);
  }
  
  void do_dfs (vector<vector<bool>>&visited, int x, int y, vector<vector<char>>&board)
  {
    visited[x][y] = false;
    
    for (int i = 0; i < 4; i++)
    {
      int updated_x = x + X[i];
      int updated_y = y + Y[i];
      
      if (isInside(updated_x,updated_y,n,m) && visited[updated_x][updated_y] && board[updated_x][updated_y] == 'O')
        do_dfs(visited,updated_x,updated_y,board);
    }
  }
  
public:
    void solve(vector<vector<char>>& board) {
      n = board.size();
      m = board[0].size();
      
      vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),true));
      
      for (int i = 0; i < board.size(); i++)
      {
        if (visited[i][0] && board[i][0] == 'O')
          do_dfs(visited,i,0,board);
        if (visited[i][m-1] && board[i][m-1] == 'O')
          do_dfs(visited,i,m-1,board);
      }
      
      for (int j = 0; j < board[0].size(); j++)
      {
        if (visited[0][j] && board[0][j] == 'O')
          do_dfs(visited,0,j,board);
        if (visited[n-1][j] && board[n-1][j] == 'O')
          do_dfs(visited,n-1,j,board);
      }
      
      for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
          if (visited[i][j] && board[i][j] == 'O')
            board[i][j] = 'X';
      
      // return board;
    }
};