class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefix;
      
      for (int i = 0; i < arr.size(); i++)
        prefix.push_back((i > 0) ? prefix[i-1]^arr[i] : arr[i]);
      
      int count = 0;
      for (int i = 0; i < arr.size(); i++)
      {
        for (int j = i+1; j < arr.size(); j++)
        {
          int XOR = (i > 0) ? prefix[i-1] ^ prefix[j] : prefix[j];
          if (XOR == 0)
            count += (j-i);
        }
      }
      return count;
    }
};