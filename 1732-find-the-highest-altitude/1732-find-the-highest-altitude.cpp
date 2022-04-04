class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> al;
      al.push_back(0);
      int maxi = 0;
      
      for (int i = 0; i < gain.size(); i++)
      {
        int sum = al[i] + gain[i];
        maxi = max(sum,maxi);
        al.push_back(sum);
      }
      return maxi;
    }
};