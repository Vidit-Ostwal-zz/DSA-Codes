/*
Time and Space Complexity O(N)
Linked List Two pointer Cycle Detection Approach 
Slow will move one time
Fast two time
Both will meet surely either at NULL or when cycle is present 
*/

class Solution {
public:  
  
  int finddigitsquare(int n)
  {
    int answer = 0;
    while (n > 0)
    {
      int remainder = n%10;
      answer += remainder*remainder;
      n = n/10;
    }
    return answer;
  }
  
    bool isHappy(int n) {
      int slow = n;
      int fast = n;
      
      do{
        slow = finddigitsquare(slow);
        fast = finddigitsquare(finddigitsquare(fast));
      }while (slow!=fast);
      
      if (slow == 1)
      {
        return true;
      }
      return false;
    }
};