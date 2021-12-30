class Solution {
public:
  
  
  /*
  Space Complexity = O(Log N) string of length number of times iteration happends
  Time Complexity = O(Log N) number is divided by 7 each iteration
  */
  
    string convertToBase7(int num) {
      /*Handling the case of num == 0*/  
      if (num == 0)
        {
          return "0";
        }
      
      
      string answer ="";
      bool flag = false;
      
      /*When number is negative change it to positive and in final representation add nagative to left side*/
      if (num <0)
      {
        flag = true;
        num = num * -1;
      }
      
      /*Making the repsentation*/
      while (num > 0)
        {
          int remain = num%7;
          num = num/7;
          answer = to_string(remain)+ answer;
        }
      
      /*Adding "-" when num is negative */
      if (flag)
      {
        answer =  "-"+ answer;
      }
      
      /*returning answer string*/
      return answer;
    }
};