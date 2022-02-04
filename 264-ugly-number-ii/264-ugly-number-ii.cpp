class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly_numbers;
      ugly_numbers.push_back(1);
      
      int index_2 = 0;
      int index_3 = 0;
      int index_5 = 0;
      
      int re_index = n;
      while (n != 1)
      {
        int next_2 = 2*ugly_numbers[index_2];
        int next_3 = 3*ugly_numbers[index_3];
        int next_5 = 5*ugly_numbers[index_5];
        
        int next_multi;
        if (next_2 < min(next_3,next_5))
          next_multi = next_2;
        
        else if (next_3 <min(next_2,next_5))
          next_multi = next_3;
        
        else if (next_5 < min(next_2,next_3))
          next_multi = next_5;
        
        else if (next_2 == next_3)
        {
          if (next_2 < next_5)
            next_multi = next_2;
          else
            next_multi = next_5;
        }
        
        else if (next_5 == next_3)
        {
          if (next_5 < next_2)
            next_multi = next_5;
          else
            next_multi = next_2;
        }
        
        else if (next_2 == next_5)
        {
          if (next_2 < next_3)
            next_multi = next_2;
          else
            next_multi = next_3;
        }
        ugly_numbers.push_back(next_multi);
        
        if (next_multi == next_2)
          index_2++;
        
        if (next_multi == next_3)
          index_3++;
        
        if (next_multi == next_5)
          index_5++;
        
        n--;
      }
      return ugly_numbers[re_index-1];
    }
};