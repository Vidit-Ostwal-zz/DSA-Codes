/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  int lengthcycle(ListNode *head)
  {
      ListNode* Slow = head;
      ListNode* Fast = head;
      int count = 0;
      while (Fast != NULL && Fast -> next != NULL)
      {
        Fast = Fast->next -> next;
        Slow = Slow-> next;
        
        if (Fast == Slow)
        {
          do 
          {
            Slow = Slow -> next;
            count++;
          }while(Slow!= Fast);
          return  count;
        }
      }
      return count;
  }
  
    ListNode *detectCycle(ListNode *head) {
        int cyclelength = lengthcycle(head);
      if (cyclelength == 0)
        return NULL;
      
      ListNode *s = head;
      ListNode *f = head;
      
      while (cyclelength != 0)
      {
        s= s->next;
        cyclelength--;
      }
      
      while (f != s)
      {
        f = f-> next;
        s = s-> next;
      }
      return f;
    }
  
};