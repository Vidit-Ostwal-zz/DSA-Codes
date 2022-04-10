class Solution {
public:
    int largestInteger(int num) {
        int temp = num;
      
      vector<bool>flag;
  
      vector<int> odd;
      vector<int> even;
      while (temp)
      {
        int f = temp%10;
        if (f%2)
        {
          odd.push_back(f);

          flag.push_back(false);
        }
        else
        {
          even.push_back(f);
       
          flag.push_back(true);
        }
        
        temp = temp/10;
      }
      
      sort(odd.begin(),odd.end(),greater<int>());
      sort(even.begin(),even.end(),greater<int>());
      reverse(flag.begin(),flag.end());
      int answer = 0;
      int i = 0;
      int j = 0;
      
      for (int k = 0; k < flag.size(); k++)
      {
        answer = answer*10;
        if (flag[k])
        {
          answer += even[i];
          i++;
        }
        else
        {
          answer += odd[j];
          j++;
        }
      }
      return answer;
    }
};