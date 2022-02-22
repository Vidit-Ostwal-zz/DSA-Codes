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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
      ListNode* temp = head;
      ListNode* temp1 = NULL;
      vector<int> c_points;
      
      int i = 1;
      while (temp -> next != NULL)
      {
        if (temp1 != NULL)
        {
          if ((temp -> val > temp -> next -> val && temp -> val >  temp1 -> val) || (temp -> val < temp -> next -> val && temp -> val <  temp1 -> val) )
            c_points.push_back(i);
        }
        temp1 = temp;
        temp = temp -> next;
        i++;
      }
      cout << c_points.size();
      int mini = INT_MAX;
      for (int i = 1; i < c_points.size(); i++)
        mini = min(mini,abs(c_points[i] -c_points[i-1]));
      
      if (c_points.size() < 2)
        return {-1,-1};
      
      return {mini,c_points[c_points.size()-1] - c_points[0]};
    }
};