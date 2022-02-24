class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
      sort(arr.begin(),arr.end());
        unordered_map<int,int> mp;
      
      for (int i = 0; i < arr.size(); i++)
      {
        if (!(arr[i]&1))
        {
          if (mp.find(arr[i]/2) != mp.end() || mp.find(arr[i]*2) != mp.end())
            return true;
        }
        else
        {
          if (mp.find(arr[i]*2) != mp.end())
            return true;
        }
        mp[arr[i]]++;
      }
      return false;
    }
};