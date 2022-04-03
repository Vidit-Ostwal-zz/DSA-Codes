class Solution {
  long long  how_many(vector<int> candies, int prt)
  {
    long long count = 0;
    for (int i  =0 ;i < candies.size(); i++)
      count += candies[i]/prt;
    
    return count;
  }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int mini = INT_MAX;
      int maxi = INT_MIN;
      long long sum = 0;
      for (int i = 0; i < candies.size(); i++)
      {
        mini = min(mini,candies[i]);
         maxi = max(maxi,candies[i]);
        sum += candies[i];
      }
      
      
      if (1*k > sum)
        return 0;
      
      int st = 1;
      int ed = maxi;
      
      long long answer = 0;
      cout << st << "  " << ed << endl;
      while (st <= ed)
      {
        int mid = st + ((ed - st) / 2);
        long long temp = how_many(candies,mid);
        // cout << temp << "   " << mid << endl;
        if ( temp >= k)
        {
          answer = max(answer,(long long)mid);
          st = mid+1;
        }
        else
        {
          ed = mid-1;
        }
        // cout << answer << endl;
      }
      // cout << answer << endl;
      return answer;
    }
};