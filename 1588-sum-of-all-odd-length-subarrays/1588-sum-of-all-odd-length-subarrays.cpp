class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> prefix;
      for (int i = 0; i < arr.size(); i++)
      {
        prefix.push_back((i > 0) ? arr[i] + prefix[i-1] : arr[i]);
        // cout << prefix[i] << "   " ;
      }
      cout << endl;
      int sum = 0;
      for (int i = 1; i <= arr.size(); i = i+2)
      {
        int a = -1;
        for (int j = i-1; j < arr.size(); j++)
        {
          sum += prefix[j];
          sum -= (a >= 0) ? prefix[a] : 0;
          a++;
        }
        // cout << sum << endl;
      }
      return sum;
    }
};