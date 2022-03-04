class Solution {
  bool check_rows_columns (vector<vector<char>>& board)
  {
    
    for (int i = 0; i < board.size(); i++)
    {
      int count = 0;
    unordered_set<int> st;
      for (int j = 0; j < board[0].size(); j++)
      {
        if (board[i][j] >= '1' && board[i][j] <= '9')
        {
          count++;
          st.insert(board[i][j] - '0');
        }
        
        if (count != st.size())
        {
          cout << i << j << endl;
          return false;
        }
      }
    }
    
    
    for (int i = 0; i < board.size(); i++)
    {
      int count1 = 0;
    unordered_set<int> st1;
      for (int j = 0; j < board[0].size(); j++)
      {
        if (board[j][i] >= '1' && board[j][i] <= '9')
        {
          count1++;
          st1.insert(board[j][i] - '0');
        }
        
        if (count1 != st1.size())
        {
          cout << i << j << endl;
          return false;
        }
      }
    }
    cout << "Hr" << endl;
    return true;
  }
  
  bool check_blocks (vector<vector<char>>& board)
  {
    for (int i = 0; i < board.size();)
    {
      for (int j = 0; j < board[0].size();)
      {
        int count = 0;
        unordered_set<int> st;
        
        for (int k = i; k < i + 3; k ++)
        {
          for (int l = j; l < j + 3; l++)
          {
            if (board[k][l] >= '1' && board[k][l] <= '9')
            {
              count++;
              st.insert(board[k][l] - '0');
            }
            if (count != st.size())
              return false;
          }
        }
        
        j = j + 3;
      }
      i = i + 3;
    }
    return true;
  }
  
  
  
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return check_rows_columns(board) && check_blocks(board);
    }
};