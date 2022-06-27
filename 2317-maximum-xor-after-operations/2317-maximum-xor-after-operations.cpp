class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        vector<int> vect (32,0);
      
      for (int i = 0; i < nums.size(); i++)
      {
        int x = nums[i];
        
        int k = 0;
        while (x)
        {
          vect[k++] += x & 1;
          x = x >> 1;
        }
      }
      
       string temp = "";
      for (int i = 0; i < vect.size(); i++)
      {
        if ((vect[i] && vect[i] % 2 == 0) || vect[i]%2)
          temp = '1' + temp;
        else
          temp = '0' + temp;
      }
      return stoi(temp,0,2);
    }
  
};