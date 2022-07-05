/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
      
      vector<vector<int>> Matrix(m,vector<int>(n,-1));
      
      if (head -> next == NULL)
      {
        Matrix[0][0] = head -> val;
        return Matrix;
      }
      
      int st_row = 0;
      int ed_row = Matrix.size()-1;
      
      int st_col = 0;
      int ed_col = Matrix[0].size()-1;
      
      while (st_row <= ed_row && st_col <= ed_col && head != NULL)
      {
        int st = st_col;
        int ed = ed_col;
        while (st < ed && head != NULL)
        {
          Matrix[st_row][st++] = head -> val;
          head = head -> next;
        }
        
        st = st_row;
        ed = ed_row;
        while (st < ed && head != NULL)
        {
          Matrix[st++][ed_col] = head -> val;
          head = head -> next;
        }
        
        st = ed_col;
        ed = st_col;
        while (st > ed && head != NULL)
        {
          Matrix[ed_row][st--] = head -> val;
          head = head -> next;
        }
        
        st = ed_row;
        ed = st_row;
        while (st > ed && head != NULL)
        {
          Matrix[st--][st_col] = head -> val;
          head = head -> next;
        }
        
        st_row++;
        st_col++;
        ed_row--;
        ed_col--;
      }
      
      return Matrix;
    }
};