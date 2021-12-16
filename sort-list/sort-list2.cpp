ListNode* get(ListNode* node, int index)
  {
    for (int i = 0 ; i < index ;i++)
    {
      node = node->next;
    }
    return node;
  }
  
  int getlength(ListNode* head)
  {
    ListNode* temp=  head;
    int count = 0;
    while (temp!= NULL)
    {
      count++;
      temp= temp->next;
    }
    return count;
  }
  
  ListNode* Final;
  void BubbleRecursive(ListNode* head, int row, int column, int length)
  {
    if (row == 0)
    {
      Final = head;
      while (head != NULL)
      {
        cout << head->val << " -> ";
        head = head-> next;
      }
      cout << "NULL" << endl;
      
      return ;
    }
    if (column < row)
    {
      ListNode* first = get(head,column);
      ListNode* second = get(head, column+1);
      ListNode* prevfirst = get(head, column-1);
      if (first->val > second->val)
      {
         if (first == head)
         {
           head = second;
           first->next = second->next;
           second-> next = first;
         }
        else if (column+1 == length-1)
        {
          prevfirst->next = second;
          second->next = first;
          first->next = NULL;
        }
        else
        {
          prevfirst->next = second;
          first->next = second->next;
          second->next = first;
        }
        
      }
      BubbleRecursive(head,row,column+1,length);
    }
    else
    {
      BubbleRecursive(head,row-1,0,length);
    }
  }
  
    ListNode* sortList(ListNode* head) {
      if (head == NULL || head -> next == NULL)
      {
        return head;
      }
      int length = getlength(head);
      BubbleRecursive(head,length-1,0,length);
      return Final;
    }
