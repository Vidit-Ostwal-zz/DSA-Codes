class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> final_vector;
      
      int temp = 1;
      
      while (temp <= n)
      {
        final_vector.push_back(temp);
        temp++;
      }
      int i = 0;
      while (n != 1)
      {
        i += k-1;
        i %= n;
        final_vector.erase(final_vector.begin()+i);
        if (i+1 == n)
          i = 0;
        n--;
      }
      return final_vector[0];
    }
};