class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2 != 0)
          return {};
      
      long long n = 2;
      long long temp = 0;
      vector<long long> temp_vector;
      while (temp + n <= finalSum)
      {
        temp += n;
        temp_vector.push_back(n);
        n += 2;
      }
      
      temp -= temp_vector[temp_vector.size()-1];
      temp_vector[temp_vector.size()-1] = finalSum - temp;
      return temp_vector;
    }
};