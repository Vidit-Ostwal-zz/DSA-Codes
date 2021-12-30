class Solution {
public:
    int kthFactor(int n, int k) {
      vector<int> factor;
        for (int i = 1 ; i <= sqrt(n) ; i++)
        {
          if (n % i == 0)
          {
            factor.push_back(i);
            if (i * i != n)
            {
               factor.push_back(n/i);
            }
          }
        }
      sort(factor.begin(),factor.end());
      if (k < factor.size()+1)
      {
        return factor[k-1];
      }
      return -1;
    }
};