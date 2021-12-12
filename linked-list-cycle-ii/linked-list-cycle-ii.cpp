/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*

Time and Space Complexity = O(N)
Problem deals with cycle therefore two pointer approach

Find the length of the cycle
Again use two pointers,
now we want them to meet at the starting of cycle,
for that we need one pointer to go through the cycle and meet at starting and other one we want to meet when it first lands there
the pointer which is traversing the cycle needs to go length of cycle more steps
that's why a while loop to traverse length of cycle time and then a loop which traverses till both are not equal
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
