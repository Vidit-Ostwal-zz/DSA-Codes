class Solution {
public:
    int addDigits(int num) {
      if (num == 0)
        return num;
      
        while (int(log10(num)) +1 != 1)
        {
          cout << num << endl;
          int temp = 0;
          while (num!= 0)
          {
            temp += num%10;
            num = num / 10;
          }
          num = temp;
        }
      return num;
    }
};