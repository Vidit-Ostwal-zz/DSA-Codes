class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int prev = 0;
      int max = INT_MIN;
      char answer;
      
      for (int i = 0; i < releaseTimes.size();i++)
      {
        int temp = releaseTimes[i] - prev;
        prev = releaseTimes[i];
        if (temp >= max)
        {
          if (temp == max)
          {
            if (keysPressed[i] - '0' > answer -'0')
            {
              answer = keysPressed[i];
            }
          }
          else
          {
          max = temp;
          answer = keysPressed[i];
          }
        }
      }
      cout << max;
      return answer;
    }
};