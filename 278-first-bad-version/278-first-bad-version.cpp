// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int st = 1;
      int end = n;
      while ( st <= end)
      {
        int mid = st + (end - st )/2;
        if (mid > 1 && isBadVersion(mid) && !isBadVersion(mid-1) || mid == 1 && isBadVersion(mid))
        {
          return mid;
        }
        if (!isBadVersion(mid))
        {
          st = mid +1;
        }
        else
        {
          end = mid -1;
        }
      }
      return -1;
    }
};