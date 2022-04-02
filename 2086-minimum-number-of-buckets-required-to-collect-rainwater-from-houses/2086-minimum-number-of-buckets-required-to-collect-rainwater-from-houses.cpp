class Solution {
public:
    int minimumBuckets(string street) {
      int count = 0;
        for (int i = 0; i < street.length(); i++)
        {
          if (street[i] == 'H')
          {
            if (i-1 >= 0 && street[i-1] == 'B')
            {}
            else if (i+1 < street.length() && street[i+1] == 'B')
            {}
            else if (i+1 < street.length() && street[i+1] == '.')
            {
              count++;
              street[i+1] = 'B';
            }
            else if (i-1 >= 0 && street[i-1] == '.')
            {
              count++;
              street[i-1] = 'B';
            }
            else
              return -1;
          }
        }
      return count;
    }
};