class Solution {
  int get_count(vector<vector<int>> board, int i, int j)
  {
    int count = 0;
    if (i -1 >= 0 && j -1 >= 0)
      count += board[i-1][j-1];
    if (i-1 >= 0)
      count += board[i-1][j];
    if (i-1 >= 0 && j+1 < board[0].size())
      count +=board[i-1][j+1];
    if (j -1 >= 0)
      count += board[i][j-1];
    if (j+1 < board[0].size())
      count += board[i][j+1];
     if (i +1 <board.size() && j -1 >= 0)
      count += board[i+1][j-1];
    if (i+1 < board.size())
      count += board[i+1][j];
    if (i+1 < board.size() && j+1 < board[0].size())
      count +=board[i+1][j+1];
    
    return count;
  }
public:
    void gameOfLife(vector<vector<int>>& board) {
        
      vector<vector<int>> temp_board(board.size(),vector<int> (board[0].size(),0));
      for (int i = 0 ; i < board.size(); i++)
          for (int j = 0; j < board[0].size(); j++)
          {
            int temp = get_count(board,i,j);
            
            if (board[i][j] == 1)
            {
              if (temp < 2)
                temp_board[i][j] = 0;
              
              else if (temp == 2 || temp == 3)
                temp_board[i][j] = 1;
              
              else
                temp_board[i][j]=  0;
            }
            else
            {
              if (temp == 3)
                temp_board[i][j] =1;
            }
          }
      board = temp_board;
    }
};