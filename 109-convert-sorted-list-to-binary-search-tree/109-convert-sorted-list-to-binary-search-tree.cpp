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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  TreeNode* convert(vector<int> nums, int start_index, int end_index)
  {
    if (start_index > end_index)
      return NULL;
    
    int mid_index = (start_index + end_index)/2;
    
    TreeNode *root = new TreeNode(nums[mid_index]);
    
    root -> left = convert(nums,start_index,mid_index-1);
    root -> right = convert(nums,mid_index+1,end_index);
    
    return root;
  }
public:
    TreeNode* sortedListToBST(ListNode* head) {
      vector<int> value;  
      while (head != NULL)
      {
        value.push_back(head->val);
        head = head -> next; 
      }  
      return convert(value,0,value.size()-1);
    }
};