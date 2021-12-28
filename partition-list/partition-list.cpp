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
  
  
  void print (ListNode *temp)
  {
    while (temp!= NULL)
    {
      cout << temp -> val << " - > " << endl;
      temp = temp -> next;
    }
  }
  
    ListNode* partition(ListNode* head, int x) {
      if (head == NULL || head -> next == NULL)
      {
        return head;
      }
       ListNode *After = new ListNode();
      ListNode *Before = new ListNode();
      ListNode *Head = Before;
      ListNode *AfterHead = After;
      ListNode *leftAfter = NULL ;
       ListNode *leftBefore = NULL;
      
      do{
        if (head -> val < x)
        {
          Before -> val = head -> val;
          Before -> next = new ListNode();
          leftBefore = Before;
          Before = Before -> next;
        }
        
        else
        {
          After -> val = head -> val;
          After -> next = new ListNode();
          leftAfter = After;
          After = After -> next;
        }
        
        head = head -> next;
      }while(head != NULL);
      
      
      if (leftBefore != NULL && leftAfter != NULL)
      {
        leftBefore -> next = AfterHead;
        leftAfter -> next = NULL;
      }
      else if (leftBefore == NULL)
      {
         leftAfter -> next = NULL;
        return AfterHead;
      }
      else if (leftAfter == NULL)
      {
        leftBefore -> next = NULL;
        return Head;
      }
     
      return Head;
    }
};